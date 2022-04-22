#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int *array;
pthread_mutex_t array_lock;

int main() {
  array = (int *)malloc(sizeof(int) * 4);

  int err = pthread_mutex_init(&array_lock, NULL);
  if (err) {
    printf("Mutex initialization failed\n");
    return err;
  }

  err = pthread_mutex_destroy(&array_lock);
  if (err) {
    printf("Mutex destruction failed\n");
    return err;
  };

  return 0;
}
