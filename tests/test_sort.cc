extern "C" {
#include <lunasort/utils.h>
}

#include "test_sort.hh"

static int cmp(const void *a, const void *b)
{
  uint32_t va = *(const uint32_t*)a;
  uint32_t vb = *(const uint32_t*)b;

  return va > vb ? 1 : (va < vb ? -1 : 0);
}

bool Sort::Test(uint32_t *data, size_t sz, void (*sort_f)(uint32_t*, size_t))
{
  uint32_t *test = array_duplicate(data, sz);
  uint32_t *ref = array_duplicate(data, sz);

  qsort(ref, sz, sizeof(uint32_t), cmp);
  sort_f(test, sz);

  bool ret = true;

  for (size_t i = 0; i < sz; ++i) {
    if (test[i] != ref[i]) {
      ret = false;
      break;
    }
  }

  free(test);
  free(ref);
  return ret;
}
