#ifndef DOT_H__
#define DOT_H__

/**
 * Dump an AST in a dot format.
 */

enum state_type {
  STATE_ROOT,
  STATE_SORT,
  STATE_VARDEC,
  STATE_NULL,
};

/**
 * Start/End of a dot file.
 */
void dot_start(void);
void dot_end(void);

/**
 * Dot state.
 */
void dot_state(const char *name, const char  *label, enum state_type type);

/**
 * Dot edge.
 */
void dot_edge(const char *src, const char *dst, const char *label);

#endif /* !DOT_H__ */
