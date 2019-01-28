#include <stdio.h>

#include <lunasort/utils.h>
#include <lunasort/sort.h>

int main(void)
{
  uint32_t *rd = array_random_create(42);
  bubble_sort_a(rd, 42);
  free(rd);
  return 0;
}
