#ifndef PARSER_H__
#define PARSER_H__

#include <stdbool.h>

#include "ast.h"

bool sort_parse(struct ast *ast, const char *sort, size_t len);

#endif /* !PARSER_H__ */