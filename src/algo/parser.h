#ifndef PARSER_H__
#define PARSER_H__

#include <stdbool.h>

#include "ast.h"

/**
 * Parse a sort algorithm which has to respect
 * the grammar 'sort.ebnf', and build the abstract syntax tree related.
 */
void algo_parse(struct ast *ast, const char *sort, size_t len);

#endif /* !PARSER_H__ */
