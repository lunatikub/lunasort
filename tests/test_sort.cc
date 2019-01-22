#include "test_sort.hh"

#define MAGIC (4096)

uint32_t* Sort::DataRandom(void)
{
  srand (time(NULL));
  uint32_t *t = new uint32_t[MAGIC];
  for (size_t i = 0; i < MAGIC; ++i) {
    t[i] = rand() % MAGIC;
  }
  return t;
}

uint32_t* Sort::DataInverted(void)
{
  uint32_t *t = new uint32_t[MAGIC];
  for (size_t i = 0; i < MAGIC; ++i) {
    t[i] = MAGIC - i - 1;
  }
  return t;
}

uint32_t* Sort::DataSorted(void)
{
  uint32_t *t = new uint32_t[MAGIC];
  for (size_t i = 0; i < MAGIC; ++i) {
    t[i] = i;
  }
  return t;
}

static uint32_t* dup(uint32_t *t)
{
  uint32_t *new_t = new uint32_t[MAGIC];
  memcpy(new_t, t, MAGIC * sizeof(uint32_t));
  return new_t;
}

static int cmp(const void *a, const void *b)
{
  uint32_t va = *(const uint32_t*)a;
  uint32_t vb = *(const uint32_t*)b;

  return va > vb ? 1 : (va < vb ? -1 : 0);
}

bool Sort::Test(uint32_t *t, void (*sort_f)(uint32_t*, size_t))
{
  uint32_t *test = dup(t);
  uint32_t *ref = dup(t);

  qsort(ref, MAGIC, sizeof(uint32_t), cmp);
  sort_f(test, MAGIC);

  bool ret = true;

  for (size_t i = 0; i < MAGIC; ++i) {
    if (test[i] != ref[i]) {
      ret = false;
      break;
    }
  }

  delete []test;
  delete []ref;
  return ret;
}
