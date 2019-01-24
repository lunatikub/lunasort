#ifndef CMP_H__
#define CMP_H__

#include <config.h>

#ifdef LUNASORT_PROFILING

#include "profiling.h"

static inline bool lt(uint32_t a, uint32_t b)
{
  profiling_cmp_inc();
  return a < b;
}

#else

/* Return true if 'a' is less than 'b', otherwise return false. */
static inline bool lt(uint32_t a, uint32_t b)
{
  return a < b;
}

#endif /* !LUNASORT_PROFILING */

#endif /* !CMP_H__ */
