#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct random {
  int x;
  int y;
};

void* func(void *arg) {
  struct random *thing = (struct random *)arg;

  printf("x: %d; y: %d\n", thing->x, thing->y);
  sleep(1);

  return NULL;
}

int main() {
  struct random a = {1, 2};
  struct random b = {3, 4};

  pthread_t threads[2] = {0};

  int err = pthread_create(&threads[0], NULL, &func, &a);
  if (err) {
    printf("pthread_create failed\n");
    return err;
  }

  err = pthread_create(&threads[1], NULL, &func, &b);
  if (err) {
    printf("pthread_create failed\n");
    return err;
  }

  for (size_t i = 0; i < 2; i++) {
    err = pthread_join(threads[i], NULL);
    if (err) {
      printf("pthread_join failed\n");
      return err;
    }
  }

  return 0;
}
