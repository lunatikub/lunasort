#include <gtest/gtest.h>

#include "test_sort.hh"

extern "C" {
#include <lunasort/sort.h>
#include <lunasort/utils.h>
}

class Insertion: public Sort
{
};

TEST_F(Insertion, Random)
{
  uint32_t *data = array_random_create(MAGIC);
  EXPECT_EQ(Test(data, MAGIC, 3, insertion_sort), true);
  free(data);
}

TEST_F(Insertion, DescendingOrder)
{
  uint32_t *data = array_sorted_descending_create(MAGIC);
  EXPECT_EQ(Test(data, MAGIC, 1, insertion_sort), true);
  free(data);
}

TEST_F(Insertion, AscendingOrder)
{
  uint32_t *data = array_sorted_ascending_create(MAGIC);
  EXPECT_EQ(Test(data, MAGIC, 1, insertion_sort), true);
  free(data);
}

TEST_F(Insertion, Random0)
{
  uint32_t *data = array_random_create(MAGIC);
  EXPECT_EQ(Test(data, MAGIC, 1, insertion_sort_o), true);
  free(data);
}

TEST_F(Insertion, RandomR)
{
  uint32_t *data = array_random_create(MAGIC);
  EXPECT_EQ(Test(data, MAGIC, 3, insertion_sort_r), true);
  free(data);
}
