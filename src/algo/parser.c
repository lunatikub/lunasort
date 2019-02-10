#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include <string.h>

#include "parser.h"
#include "lexer.h"
#include "tokentype2str.h"

static void node_set(struct ast_node **dst, void *src)
{
  *dst = (struct ast_node*)src;
}

static void node_init(struct ast_node *node, enum node_type type)
{
  node->next = NULL;
  node->child = NULL;
  node->type = type;
}

static void* node_new(enum node_type type, size_t sz)
{
  struct ast_node *node = malloc(sz);
  assert(node != NULL);
  node_init(node, type);
  return node;
}

static char* token_strndup(const char *sort, const struct token *tok)
{
  return strndup(&sort[tok->start], tok->end - tok->start);
}

static void expect_and_eat(struct token *tok, const char *sort,
                           size_t len, enum token_type type)
{
  lexer_token_fill(sort, len, tok);
  assert(tok->type == type);
  lexer_token_eat(tok);
}

/**
 * vardec =
 *       id type
 *       ;
 */
static void
vardec_parse(struct ast_node **node, struct token *tok,
             const char *sort, size_t len)
{
  struct ast_vardec *vardec_node =
    node_new(NODE_VARDEC, sizeof(*vardec_node));

  /* Expected id (Name of the var). */
  lexer_token_fill(sort, len, tok);
  assert(tok->type == TOKEN_ID);
  vardec_node->name = token_strndup(sort, tok);
  lexer_token_eat(tok); /* Eat the id */

  /* Expected type. */
  lexer_token_fill(sort, len, tok);
  assert(tok->type == TOKEN_TYPE);
  vardec_node->type = token_strndup(sort, tok);
  lexer_token_eat(tok);

  node_set(node, vardec_node);

  lexer_token_fill(sort, len, tok);
  lexer_token_eat(tok);
  /* End of vardec. */
  if (tok->type == TOKEN_CLOSING_BRACE) {
    return;
  }
  /* New vardec. */
  if (tok->type == TOKEN_COMA) {
    vardec_parse(&vardec_node->node.next, tok, sort, len);
    return;
  }

  fprintf(stderr, "[line:%lu] expected token: ',' or '}' instead of '%s'.\n",
          tok->line, tokentype2str(tok->type));
  abort();
}

/**
 * declaration =
 *       'Declaration' '{' vardec ',' vardec? '}'
 *       ;
 */
static void
declaration_parse(struct ast_node *node, struct token *tok,
                  const char *sort, size_t len)
{
  /* Expect 'Declaration'. */
  expect_and_eat(tok, sort, len, TOKEN_DECLARATION);
  /* Expect '{'. */
  expect_and_eat(tok, sort, len, TOKEN_OPENING_BRACE);

  vardec_parse(&node->next, tok, sort, len);
}

/**
 * sort =
 *       id '{' declaration implementation '}'
 *       ;
 */
static void
sort_parse(struct ast_node *root_node, struct token *tok,
           const char *sort, size_t len)
{
  /* Expected id (Name of the sort algo). */
  lexer_token_fill(sort, len, tok);
  assert(tok->type == TOKEN_ID);
  struct ast_sort *sort_node = node_new(NODE_SORT, sizeof(*sort_node));
  sort_node->name = token_strndup(sort, tok);
  lexer_token_eat(tok);

  /* Expected '{'. */
  expect_and_eat(tok, sort, len, TOKEN_OPENING_BRACE);

  declaration_parse(&sort_node->node, tok, sort, len);
  node_set(&root_node->child, sort_node);
}

void algo_parse(struct ast *ast, const char *sort, size_t len)
{
  DECLARE_TOKEN(tok);
  node_init(&ast->root, NODE_ROOT);
  sort_parse(&ast->root, &tok, sort, len);
}
