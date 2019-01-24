#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "options.h"

static void option_default(struct options *options)
{
  options->size = 42;
  options->kpi = false;
  options->cycle = false;
}

static void usage(void)
{
  fprintf(stderr, "./lunasort -[k|c] -s 10\n");
  exit(1);
}

void option_parse(int argc, char **argv, struct options *options)
{
  int c;

  option_default(options);

  while ((c = getopt(argc , argv, "cks:")) != -1) {
    switch (c) {
      case 'c':
        options->cycle = true;
        break;
      case 'k':
        options->kpi = true;
        break;
      case 's':
        options->size = atoi(optarg);
        break;
      case '?':
        usage();
        break;
    }
  }
}
