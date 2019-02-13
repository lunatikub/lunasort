#ifndef LEXER_H__
#define LEXER_H__

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

struct token {
  enum token_type type;
  size_t start; /* offset of the token start. */
  size_t end; /* offset of the token end. */
  size_t line;
};

#define DECLARE_TOKEN(NAME)                     \
  struct token NAME = {                         \
    .start = 0,                                 \
    .line = 1,                                  \
    .type = TOKEN_NULL,                         \
  }

/**
 * Fill the next token or assert in case of error.
 */
void lexer_token_fill(const char *sort, size_t len, struct token *tok);

/**
 * Eat the token filled by 'lexer_token_fill'.
 */
void lexer_token_eat(struct token *tok);

#endif /* !LEXER_H__ */
