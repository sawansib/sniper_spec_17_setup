#include "sift_utils.h"

#include <cstdio>

#include "sift_format.h"

void Sift::hexdump(const void *__data, uint32_t size) {
  unsigned char *data = (unsigned char *)__data;
  printf("(%d) ", size);
  for (unsigned int i = 0; i < size; ++i) {
    if (data[i])
      printf("%02x ", data[i]);
    else
      printf(".. ");
  }
  printf("\n");
}
