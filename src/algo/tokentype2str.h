#ifndef TOKENTYPE2STR_H__
#define TOKENTYPE2STR_H__

#include <stdlib.h>

static inline const char* tokentype2str(enum token_type type)
{
  switch (type) {
    case TOKEN_NULL: return "NULL";
    case TOKEN_ID: return "ID";
    case TOKEN_FOR: return "for";
    case TOKEN_OPENING_PARENT: return "(";
    case TOKEN_CLOSING_PARENT: return ")";
    case TOKEN_OPENING_BRACE: return "{";
    case TOKEN_CLOSING_BRACE: return "}";
    case TOKEN_COMA: return ",";
    case TOKEN_NUMBER: return "NUMBER";
    case TOKEN_DECLARATION: return "Declaration {}";
    case TOKEN_TYPE: return "TYPE";
    case TOKEN_END: return "end";
  };
  abort();
}

#endif /* !TOKENTYPE2STR_H__ */
