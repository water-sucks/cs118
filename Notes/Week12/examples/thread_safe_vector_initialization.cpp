#include <iostream>
#include <vector>
#include <pthread.h>

struct args {
  std::vector<int>* list;
  pthread_mutex_t *mutex;
};

void* initialize_vector(void *arg) {
  auto p = reinterpret_cast<args *>(arg);

  pthread_mutex_lock(p->mutex);

  *(p->list) = std::vector<int>(100, 0);

  pthread_mutex_unlock(p->mutex);

  return NULL;
}

int main() {
  std::vector<int> x;
  pthread_mutex_t m;

  int err = pthread_mutex_init(&m, NULL);
  if (err) {
    std::cout << "Mutex initialization failed" << "\n";
    return err;
  }

  struct args d = {&x, &m};

  pthread_t thread;
  
  err = pthread_create(&thread, NULL, &initialize_vector, &d);
  if (err) {
    std::cout << "Thread initialization failed" << "\n";
    return err;
  }

  err = pthread_join(thread, NULL);
  if (err) {
    std::cout << "Thread join failed" << "\n";
    return err;
  }

  err = pthread_mutex_destroy(&m);
  if (err) {
    std::cout << "Mutex destruction failed" << "\n";
  }

  return 0;
}
