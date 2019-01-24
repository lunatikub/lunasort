#include <stdio.h>
#include <stdint.h>

#include "profiling.h"

static uint64_t cmp;
static uint64_t swap;
static uint64_t start;

/* Read time stamp counter. */
#ifdef __amd64
static __inline__ unsigned long long rdtsc(void)
{
  unsigned hi, lo;
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}
#else
#error "only x86_64 supported"
#endif

void profiling_start(void)
{
  cmp = 0;
  swap = 0;
  start = rdtsc();
}

void profiling_stop(const char *sort_name, bool kpi, bool cycle)
{
  uint64_t lap = rdtsc() - start;

  if (kpi) {
    printf("kpi,%s,%lu,%lu\n", sort_name, cmp, swap);
  }
  if (cycle) {
    printf("cycle,%s,%lu\n", sort_name, lap);
  }
}

void profiling_cmp_inc(void)
{
  ++cmp;
}

void profiling_swap_inc(void)
{
  ++swap;
}

uint64_t profiling_cmp_get(void)
{
  return cmp;
}

uint64_t profiling_swap_get(void)
{
  return swap;
}
