#ifndef TOKENTYPE2STR_H__
#define TOKENTYPE2STR_H__

static inline std::string tokentype2str(enum token_type type)
{
  switch (type) {
    case TOKEN_NULL: return "null";
    case TOKEN_ID: return "identifier";
    case TOKEN_FOR: return "for";
    case TOKEN_OPENING_PARENT: return "opengin parent";
    case TOKEN_CLOSING_PARENT: return "closing parent";
    case TOKEN_OPENING_BRACE: return "opengin brace";
    case TOKEN_CLOSING_BRACE: return "closing brace";
    case TOKEN_COMA: return "coma";
    case TOKEN_NUMBER: return "number";
    case TOKEN_DECLARATION: return "declaration";
    case TOKEN_TYPE: return "type";
    case TOKEN_END: return "end";
  };
  abort();
}

#endif /* !TOKENTYPE2STR_H__ */
