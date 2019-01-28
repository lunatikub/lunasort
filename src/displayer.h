#ifndef DISPLAYER_H__
#define DISPLAYER_H__

#include <stdint.h>
#include <stddef.h>

/**
 * 0: step by step.
 * >0: Number of us between each step.
 */
#define T (0)

/* Main section */
void disp_start(size_t sz);
void disp_stop(void);

/* Array section */
void disp_array(uint32_t *ptr, size_t sz);

/* Algorithm section */
void disp_algo_code(int line, const char *algo);
void disp_algo_cursor(int line);

/* Operations section */
void disp_op_swap(uint32_t *ptr, uint32_t a, uint32_t b);
void disp_op_lt(uint32_t *ptr, uint32_t a, uint32_t b);

/* Variables section */
void disp_var_add(uint32_t id, const char *name);
void disp_var_update(uint32_t id, size_t value);

#endif /* !DISPLAYER_H__ */
