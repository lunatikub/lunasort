#ifndef SWAP_H__
#define SWAP_H__

#include <config.h>

#ifdef LUNASORT_PROFILING

#include "profiling.h"

static inline void swap(uint32_t *a, uint32_t *b)
{
  profiling_swap_inc();
  uint32_t tmp = *a;
  *a = *b;
  *b = tmp;
}

#else

static inline void swap(uint32_t *a, uint32_t *b)
{
  uint32_t tmp = *a;
  *a = *b;
  *b = tmp;
}

#endif /* !LUNASORT_PROFILING */

#endif /* !SWAP_H__ */
