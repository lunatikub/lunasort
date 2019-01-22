#ifndef TEST_SORT_H__
#define TEST_SORT_H__

#include <gtest/gtest.h>

extern "C" {
#include <lunasort/sort.h>
}

class Sort: public testing::Test
{
public:
  /* Random data: [ 42, 1, 5, 12, 27, 31, ...] */
  uint32_t* DataRandom(void);

  /* Inverted data: [ 42, 41, 40, ... ] */
  uint32_t* DataInverted(void);

  /* Sorted data: [ 0, 1, 2, 3, 4, ... ] */
  uint32_t* DataSorted(void);

  bool Test(uint32_t *t, void (*sort_f)(uint32_t*, size_t));
};

#endif /* !TEST_SORT_H__ */
