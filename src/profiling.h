#ifndef PROFILING_H__
#define PROFILING_H__

#include <stdbool.h>

/* Start profiling. */
void profiling_start(void);

/* Stop profiling. */
void profiling_stop(const char *sort_name, bool kpi, bool cycle);

/* Increment KPI. */
void profiling_cmp_inc(void);
void profiling_swap_inc(void);
void profiling_get_inc(void);
void profiling_set_inc(void);

#endif /* !PROFILING_H__ */
