#include <string.h>
#include <lunasort/utils.h>

uint32_t* array_random_create(size_t sz)
{
  uint32_t *t = malloc(sz * sizeof(uint32_t));
  for (size_t i = 0; i < sz; ++i) {
    t[i] = rand() % sz;
  }
  return t;
}

uint32_t* array_sorted_ascending_create(size_t sz)
{
  uint32_t *t = malloc(sz * sizeof(uint32_t));
  for (size_t i = 0; i < sz; ++i) {
    t[i] = i;
  }
  return t;
}

uint32_t* array_sorted_descending_create(size_t sz)
{
  uint32_t *t = malloc(sz * sizeof(uint32_t));
  for (size_t i = 0; i < sz; ++i) {
    t[i] = sz - i - 1;
  }
  return t;
}

uint32_t* array_duplicate(uint32_t *array, size_t sz)
{
  uint32_t *new_array = malloc(sz * sizeof(uint32_t));
  memcpy(new_array, array, sz * sizeof(uint32_t));
  return new_array;
}
