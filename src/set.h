#ifndef SET_H__
#define SET_H__

#include <config.h>

#ifdef LUNASORT_PROFILING

#include "profiling.h"

static inline uint32_t set(uint32_t a)
{
  profiling_set_inc();
  return a;
}

#else

static inline uint32_t set(uint32_t a)
{
  return a;
}

#endif /* !LUNASORT_PROFILING */

#endif /* !SET_H__ */
