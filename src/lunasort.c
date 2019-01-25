#include <lunasort/utils.h>
#include <lunasort/sort.h>

#include "profiling.h"
#include "options.h"

/**
 * List of sort algorithm.
 */
struct lunasort {
  const char *name;
  void (*sort_f)(uint32_t *ptr, size_t sz);
} sorts[] = {
  { "bubble", bubble_sort },
  { "bubble_o", bubble_sort_o },
  { "insertion", insertion_sort },
  { "insertion_o", insertion_sort_o },
  { "insertion_r", insertion_sort_r },
  { NULL, NULL },
};

struct data {
  uint32_t *rd; /* Random. */
  uint32_t *dd; /* Sorted descending order. */
  uint32_t *ad; /* Sorted ascending order. */
};

static void lunasort_process(struct lunasort *sort,
                             struct options *options,
                             struct data *data)
{
  size_t sz = options->size;
  uint32_t *dup = array_duplicate(data->rd, sz);

  profiling_start();
  {
    sort->sort_f(dup, sz);
  }
  profiling_stop(sort->name, options->kpi, options->cycle);

  free(dup);
}

static void lunasort_data_create(size_t size, struct data *data)
{
  data->rd = array_random_create(size);
  data->dd = array_sorted_descending_create(size);
  data->ad = array_sorted_ascending_create(size);
}

static void lunasort_data_destroy(struct data *data)
{
  free(data->rd);
  free(data->dd);
  free(data->ad);
}

int main(int argc, char **argv)
{
  struct options options;
  struct data data;

  option_parse(argc, argv, &options);

  lunasort_data_create(options.size, &data);
  for (struct lunasort *iter = &sorts[0]; iter->name != NULL; ++iter) {
    lunasort_process(iter, &options, &data);
  }
  lunasort_data_destroy(&data);

  return 0;
}
