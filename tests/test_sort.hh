#ifndef TEST_SORT_H__
#define TEST_SORT_H__

#include <gtest/gtest.h>

extern "C" {
#include <lunasort/sort.h>
}

#define MAGIC (4096)

class Sort: public testing::Test
{
public:
  bool Test(uint32_t *t, size_t sz, void (*sort_f)(uint32_t*, size_t));
};

#endif /* !TEST_SORT_H__ */
