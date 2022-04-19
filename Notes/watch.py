"""
Watch notes and rebuild PDFs if they are modified or created
"""

import os
import sys
import subprocess
import time
from watchdog.observers import Observer
from watchdog.events import FileClosedEvent, PatternMatchingEventHandler


class Watch:
    def __init__(self, directory: str) -> None:
        self.directory = directory
        self.observer = Observer()

    def run(self):
        event_handler = Handler(patterns=["*.md"])
        self.observer.schedule(event_handler, self.directory, recursive=True)
        self.observer.start()
        try:
            while True:
                time.sleep(5)
        except Exception:
            print("Stopping observer")
        finally:
            self.observer.stop()
        self.observer.join()


class Handler(PatternMatchingEventHandler):
    def __init__(
        self,
        patterns=None,
        ignore_patterns=None,
        ignore_directories=True,
        case_sensitive=True,
    ):
        super().__init__(
            patterns,
            ignore_patterns,
            ignore_directories,
            case_sensitive,
        )

    @staticmethod
    def on_closed(event:   FileClosedEvent) -> None:
        if event.is_directory or event.is_synthetic:
            return
        destination = event.src_path.replace(".md", ".pdf")
        subprocess.run(
            [
                "pandoc",
                "-f",
                "markdown",
                event.src_path,
                "-o",
                destination,
            ]
        )


class LockFile:
    def __init__(self, file_name: str):
        self.is_locked = False
        self.lockfile = file_name

    def create(self):
        
        try:
            self.handle = os.open(
                self.lockfile,
                os.O_CREAT | os.O_EXCL | os.O_RDWR,
            )
            self.is_locked = True
        except Exception:
            print("Could not lock process. Is there another watcher running?")
            exit(1)

    def release(self):
        os.close(self.handle)
        os.unlink(self.lockfile)

    def __enter__(self):
        return self.handle if self.is_locked else self.create()

    def __exit__(self):
        pass


if __name__ == "__main__":
    with LockFile("/tmp/.cs188-watch.lock"):
        watch = Watch(sys.argv[1] if len(sys.argv) > 1 else "./")
        watch.run()
