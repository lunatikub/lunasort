#ifndef AST_H__
#define AST_H__

#include <stdint.h>

#include <lunasort/utils/container_of.h>

enum node_type {
  NODE_ROOT,
  NODE_SORT,
  NODE_VARDEC,
};

/**
 * Generic node.
 */
struct ast_node {
  enum node_type type;
  struct ast_node *next;
  struct ast_node *child;
};

#define ast_sort_get(n) (container_of(n, struct ast_sort, node))

/**
 * Sort node
 * { next -> vardec_node, child -> ? }
 */
struct ast_sort {
  struct ast_node node;
  const char *name;
};

#define ast_vardec_get(n) (container_of(n, struct ast_vardec, node))

/**
 * Vardec node
 * { next -> vardec_node, child -> NULL }
 */
struct ast_vardec {
  struct ast_node node;
  const char *name;
  const char *type;
};

/**
 * Root node
 * { next -> NULL, child -> sort_node }
 */
struct ast {
  struct ast_node root;
};

#endif /* !AST_H__ */
