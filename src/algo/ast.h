#ifndef AST_H__
#define AST_H__

/**
 * Sort node.
 * NameSort { Declaration {} Implementation {} }
 */
struct ast_sort {
  const char *name;
  struct declaration *declaration;
  struct implementation *implementation;
};

struct ast {
  struct ast_sort sort;
};

#endif /* !AST_H__ */
