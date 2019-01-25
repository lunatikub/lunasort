#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include <lunasort/sort.h>

#include "operation.h"

void insertion_sort(uint32_t *ptr, size_t sz)
{
  for (size_t i = 1; i < sz; ++i) {
    size_t j = i;
    while (j > 0 && gt(get(ptr, j - 1), get(ptr, j))) {
      swap(&ptr[j], &ptr[j - 1]);
      --j;
    }
  }
}

void insertion_sort_o(uint32_t *ptr, size_t sz)
{
  for (size_t i = 1; i < sz; ++i) {
    uint32_t x = get(ptr, i);
    size_t j = i;
    while (j > 0 && gt(get(ptr, j - 1), x)) {
      ptr[j] = set(ptr[j - 1]);
      --j;
    }
    ptr[j] = set(x);
  }
}

static void isr(uint32_t *ptr, size_t n)
{
  if (eq(n, 0)) {
    return;
  }

  isr(ptr, n - 1);
  uint32_t x = get(ptr, n);
  size_t j = n - 1;
  while (j >= 0 && gt(get(ptr, j), x)) {
    ptr[j + 1] = set(ptr[j]);
    --j;
  }
  ptr[j + 1] = set(x);
}

void insertion_sort_r(uint32_t *ptr, size_t sz)
{
  isr(ptr, sz - 1);
}
