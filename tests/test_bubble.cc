#include <gtest/gtest.h>

#include "test_sort.hh"

extern "C" {
#include <lunasort/sort.h>
#include <lunasort/utils.h>
}

class Bubble: public Sort
{
};

TEST_F(Bubble, Random)
{
  uint32_t *data = array_random_create(MAGIC);
  EXPECT_EQ(Test(data, MAGIC, 3, bubble_sort), true);
  free(data);
}

TEST_F(Bubble, DescendingOrder)
{
  uint32_t *data = array_sorted_descending_create(MAGIC);
  EXPECT_EQ(Test(data, MAGIC, 1, bubble_sort), true);
  free(data);
}

TEST_F(Bubble, AscendingOrder)
{
  uint32_t *data = array_sorted_ascending_create(MAGIC);
  EXPECT_EQ(Test(data, MAGIC, 1, bubble_sort), true);
  free(data);
}

TEST_F(Bubble, RandomO)
{
  uint32_t *data = array_random_create(MAGIC);
  EXPECT_EQ(Test(data, MAGIC, 1, bubble_sort_o), true);
  free(data);
}
