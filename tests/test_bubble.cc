#include <gtest/gtest.h>

#include "test_sort.hh"

extern "C" {
#include <lunasort/sort.h>
}

class Bubble: public Sort
{
};

TEST_F(Bubble, Random)
{
  uint32_t *t = DataRandom();
  EXPECT_EQ(Test(t, bubble_sort), true);
  delete []t;
}

TEST_F(Bubble, Inverted)
{
  uint32_t *t = DataInverted();
  EXPECT_EQ(Test(t, bubble_sort), true);
  delete []t;
}

TEST_F(Bubble, Sorted)
{
  uint32_t *t = DataSorted();
  EXPECT_EQ(Test(t, bubble_sort), true);
  delete []t;
}
