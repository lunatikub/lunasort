#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include "profiling.h"

struct profiling {
  uint64_t cmp;
  uint64_t swap;
  uint64_t set;
  uint64_t get;
  uint64_t start;
};

static struct profiling profil;

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
  memset(&profil, 0, sizeof(struct profiling));
  profil.start = rdtsc();
  printf("kpi,name,cmp,swap,set,get\n");
  printf("cycle,name,cycles\n");
}

void profiling_stop(const char *sort_name, bool kpi, bool cycle)
{
  uint64_t lap = rdtsc() - profil.start;

  if (kpi) {
    printf("kpi,%s,%lu,%lu,%lu,%lu\n",
           sort_name, profil.cmp, profil.swap,
           profil.set, profil.get);
  }
  if (cycle) {
    printf("cycle,%s,%lu\n", sort_name, lap);
  }
}

void profiling_cmp_inc(void)
{
  __atomic_add_fetch(&profil.cmp, 1, __ATOMIC_SEQ_CST);
}

void profiling_swap_inc(void)
{
  __atomic_add_fetch(&profil.swap, 1, __ATOMIC_SEQ_CST);
}

void profiling_set_inc(void)
{
  __atomic_add_fetch(&profil.set, 1, __ATOMIC_SEQ_CST);
}

void profiling_get_inc(void)
{
  __atomic_add_fetch(&profil.get, 1, __ATOMIC_SEQ_CST);
}
