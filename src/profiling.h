#ifndef PROFILING_H__
#define PROFILING_H__

#include <stdbool.h>

/* Start profiling. */
void profiling_start(void);

/* Stop profiling. */
void profiling_stop(const char *sort_name, bool kpi, bool cycle);

/* Increment 'cmp' KPI. */
void profiling_cmp_inc(void);

/* Increment 'swap' KPI. */
void profiling_swap_inc(void);

/* Get 'cmp' KPI. */
uint64_t profiling_cmp_get(void);

/* Get 'swap' KPI. */
uint64_t profiling_swap_get(void);

#endif /* !PROFILING_H__ */
