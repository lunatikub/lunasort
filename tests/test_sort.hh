#ifndef TEST_SORT_H__
#define TEST_SORT_H__

#include <gtest/gtest.h>

extern "C" {
#include <lunasort/sort.h>
}

#define MAGIC (1024)

class Sort: public testing::Test
{
public:
  bool Test(uint32_t *t, size_t sz, uint32_t nr,
            void (*sort_f)(uint32_t*, size_t));
};

#endif /* !TEST_SORT_H__ */
