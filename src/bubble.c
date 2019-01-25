#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include <lunasort/sort.h>

#include "operation.h"

void bubble_sort(uint32_t *ptr, size_t sz)
{
  for (size_t i = sz - 1; i > 0;--i) {
    for (size_t j = 0; j < i; ++j) {
      if (lt(ptr[j + 1], ptr[j])) {
        swap(&ptr[j + 1], &ptr[j]);
      }
    }
  }
}

void bubble_sort_o(uint32_t *ptr, size_t sz)
{
  for (size_t i = sz - 1; i > 0;--i) {
    bool swapped = set(true);
    for (size_t j = 0; j < i; ++j) {
      if (lt(ptr[j + 1], ptr[j])) {
        swap(&ptr[j + 1], &ptr[j]);
        swapped = set(false);
      }
    }
    if (eq(swapped, true)) {
      break;
    }
  }
}
