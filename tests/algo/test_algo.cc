#include "test_algo.hh"
#include "tokentype2str.h"

GTEST_API_ int
main(int argc, char **argv)
{
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

void Algo::SetUp(void)
{
  tok.start = 0;
  tok.end = 0;
  tok.line = 1;
  tok.type = TOKEN_NULL;
}

void Algo::TearDown(void)
{
}

void Algo::TokDump(void)
{
  std::cout << sort.substr(tok.start, tok.end) << std::endl;
}

bool Algo::TokEq(const std::string &str, enum token_type type)
{
  size_t len = (tok.end - tok.start  == 0)
    ? 1 : tok.end - tok.start;

  const std::string s = sort.substr(tok.start, len);

  EXPECT_EQ(s, str) <<
    "Lexer test error: token, " <<
    "expected: " << str << ", " <<
    "result: " << s << std::endl;

  EXPECT_EQ(type, tok.type) <<
    "Lexer test error: token type, " <<
    "expected: " << tokentype2str(type) << ", " <<
    "result: " << tokentype2str(tok.type) << std::endl;

  return s == str && type == tok.type;
}
