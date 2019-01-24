#ifndef OPTIONS_H__
#define OPTIONS_H__

#include <stdint.h>
#include <stdbool.h>

struct options {
  size_t size;
  bool kpi;
  bool cycle;
};

/**
 * Parse the options of lunasort.
 */
void option_parse(int argc, char **argv, struct options *options);

#endif /* !OPTIONS_H__ */
