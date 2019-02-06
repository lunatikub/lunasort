#include "test_algo.hh"

struct token_list {
  const std::string str;
  enum token_type type;
};

class Lexer: public Algo
{
protected:
  void Test(const struct token_list *toks, size_t sz);
};

void Lexer::Test(const struct token_list *toks, size_t sz)
{
  const struct token_list *iter;
  for (iter = &toks[0]; iter != &toks[sz]; ++iter) {
    EXPECT_TRUE(lexer_token_fill(sort.c_str(), sort.length(), &tok));
    ASSERT_TRUE(TokEq(iter->str, iter->type)) <<
      "Lexer test error: '" << iter->str <<
      "', tok.err: " << tok.err << std::endl;
    lexer_token_eat(&tok);
  }
  lexer_token_fill(sort.c_str(), sort.length(), &tok);
  ASSERT_EQ(tok.type, TOKEN_END) <<
    "Lexer test error: expected end" << std::endl;
}

#define TOKS_SZ(TOKS) (sizeof(TOKS) / sizeof(TOKS[0]))

const static struct token_list foo_toks[] = {
  { "FooSort", TOKEN_ID },
  { "(", TOKEN_OPENING_PARENT },
  { ")", TOKEN_CLOSING_PARENT },
  { "{", TOKEN_OPENING_BRACE },
  { "Declaration", TOKEN_DECLARATION },
  { "{", TOKEN_OPENING_BRACE },
  { "i", TOKEN_ID },
  { "int", TOKEN_TYPE },
  { ",", TOKEN_COMA },
  { "j", TOKEN_ID },
  { "int", TOKEN_TYPE },
  { ",", TOKEN_COMA },
  { "}", TOKEN_CLOSING_BRACE },
  { "}", TOKEN_CLOSING_BRACE },
};

TEST_F(Lexer, Declaration)
{
  sort = "\
      FooSort()\
      {\
        Declaration {\
          i int,\
          j int,\
        }\
      }";

  Test(foo_toks, TOKS_SZ(foo_toks));
}

