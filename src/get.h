#ifndef GET_H__
#define GET_H__

#include <config.h>

#ifdef LUNASORT_PROFILING

#include "profiling.h"

static inline uint32_t get(uint32_t *ptr, size_t i)
{
  profiling_get_inc();
  return ptr[i];
}

#else

static inline uint32_t get(uint32_t *ptr, size_t i)
{
  return ptr[i];
}

#endif /* !LUNASORT_PROFILING */

#endif /* !GET_H__ */
