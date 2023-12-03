/*NO LEGAL*/
#include <pthread.h>

#include <cstdlib>
#include <iostream>

static void *child(void *);
static void *parent(void *);

int main() {
  pthread_t tid;
  if (pthread_create(&tid, 0, child, 0) != 0)
    std::cerr << "Unable to create thread\n";
  parent(0);

  pthread_join(tid, 0);
  return 0;
}

static void *child(void *) {
  malloc(1);
  std::cout << "This is the child\n";
  return 0;
}

static void *parent(void *) {
  malloc(1);
  std::cout << "This is the parent\n";
  return 0;
}
