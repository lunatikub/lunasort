#include <stddef.h>

#include "parser.h"
#include "lexer.h"

bool sort_parse(struct ast *ast, const char *sort, size_t len)
{
    DECLARE_TOKEN(tok);

    if (lexer_token_fill(sort, len, &tok) == false) {
        return false;
    }

    return true;
}