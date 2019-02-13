#ifndef TEST_ALGO_H__
#define TEST_ALGO_H__

#include <gtest/gtest.h>

extern "C" {
#include "lexer.h"
}

class Algo: public testing::Test
{
protected:
  virtual void SetUp(void);
  virtual void TearDown(void);

  void TokDump(void);
  bool TokEq(const std::string &str, enum token_type type);

  std::string sort;
  struct token tok;
};

#endif /* !TEST_ALGO_H__ */
