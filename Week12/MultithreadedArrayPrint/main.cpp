#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct args {
  int *start;
  int size;
};

void *print_array(void *args) {
  struct args *p = (struct args *)args;

  for (size_t i = 0; i < p->size; i++) {
    std::cout << (p->start)[i] << "\n";
  }

  return NULL;
}

int main() {
  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  struct args x = {array, 5};
  struct args y = {array + 5, 5};

  pthread_t threads[2] = {0};

  // Thread 1
  int err = pthread_create(&threads[0], NULL, &print_array, &x);
  if (err) {
    std::cout << "pthread_create: error: " << strerror(err);
    return err;
  } else {
    std::cout << "pthread_create: ID: " << threads << std::endl;
  }

  // Thread 2
  err = pthread_create(&threads[1], NULL, &print_array, &y);
  if (err) {
    std::cout << "pthread_create: error: " << strerror(err);
    return err;
  } else {
    std::cout << "pthread_create: ID: " << threads << std::endl;
  }

  // Join
  for (int i = 0; i < 2; i++) {
    err = pthread_join(threads[i], NULL);
    if (err) {
      std::cout << "pthread_join: error: " << strerror(err) << std::endl;
      return err;
    }
  }

  return 0;
}
