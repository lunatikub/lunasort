#ifndef LEXER_H_HH
#define LEXER_H_HH

#include <stddef.h>
#include <stdbool.h>

enum token_type {
  TOKEN_NULL,
  TOKEN_ID,
  TOKEN_FOR,
  TOKEN_OPENING_PARENT, /* ( */
  TOKEN_CLOSING_PARENT, /* ) */
  TOKEN_OPENING_BRACE, /* { */
  TOKEN_CLOSING_BRACE, /* } */
  TOKEN_COMA, /* , */
  TOKEN_NUMBER,
  TOKEN_DECLARATION, /* Declaration */
  TOKEN_TYPE, /* int, []int */
  TOKEN_END,
};

#define ERR_SZ (256)

struct token {
  enum token_type type;
  size_t start;
  size_t end;
  size_t line;
  char err[ERR_SZ];
};

bool lexer_token_fill(const char *sort, size_t len, struct token *tok);

void lexer_token_eat(struct token *tok);

#endif /* !LEXER_H_HH */
