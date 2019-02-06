#include <stdio.h>
#include <string.h>

#include <lunasort/utils/file.h>

#include "lexer.h"
#include "tokentype2str.h"

int main(int argc, char **argv)
{
    DECLARE_TOKEN(tok);

    if (argc != 2) {
        fprintf(stderr, "Usage: ./lexer_dump algo.sort\n");
        return -1;
    }

    size_t len;
    char *sort = filetobuf(argv[1], &len);
    if (sort == NULL) {
        fprintf(stderr, "Error: open file %s.\n", argv[1]);
        return -1;
    }

    printf("%s", sort);

    while (tok.type != TOKEN_END) {
        if (lexer_token_fill(sort, len, &tok) == false) {
            return -1;
        }
        printf("{%s}: '", tokentype2str(tok.type));
        int l = tok.end - tok.start;
        for (int i = 0; i < l; ++i) {
            if (sort[tok.start + i] != '\n') {
                printf("%c", sort[tok.start + i]);
            }
          
        }
        printf("'\n");
        lexer_token_eat(&tok);
    }

    return 0;
}