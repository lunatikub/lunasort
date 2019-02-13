#include <stdlib.h>
#include <stdio.h>

#include <lunasort/utils/dot.h>

void dot_start(void)
{
  printf("digraph {\n");
}

void dot_end(void)
{
  printf("}\n");
}

static const char* dot_shape_get(enum state_type type)
{
  switch(type) {
    case STATE_ROOT: return "doubleoctagon";
    case STATE_NULL: return "box";
    case STATE_SORT: return "octagon";
    case STATE_VARDEC: return "oval";
  };
  abort();
}

static const char* dot_color_get(enum state_type type)
{
  switch (type) {
    case STATE_ROOT: return "chartreuse4";
    case STATE_NULL: return "red";
    case STATE_SORT: return "darkorange";
    case STATE_VARDEC: return "cornsilk4";
  };
  abort();
}

void dot_state(const char *name, const char  *label, enum state_type type)
{
  printf("\t%s [shape=%s, color=%s, label=\" %s\"]\n",
         name, dot_shape_get(type), dot_color_get(type), label);
}

void dot_edge(const char *src, const char *dst, const char *label)
{
  printf("\t%s -> %s [label=\" %s\"]\n", src, dst, label);
}
