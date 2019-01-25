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

bool Sort::Test(uint32_t *data, size_t sz, uint32_t nr,
                void (*sort_f)(uint32_t*, size_t))
{
  for (uint32_t i = 0; i < nr; ++i) {
    uint32_t *test = array_duplicate(data, sz);
    uint32_t *ref = array_duplicate(data, sz);

    qsort(ref, sz, sizeof(uint32_t), cmp);
    sort_f(test, sz);

    int ret = memcmp(test, ref, sizeof(uint32_t) * sz);
    free(test);
    free(ref);
    if (ret != 0) {
      return false;
    }
  }
  return true;
}
