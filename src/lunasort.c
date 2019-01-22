#include <time.h>

#include <lunasort/utils.h>

int main(void)
{
  srand (time(NULL));
  uint32_t *data = array_random_create(2048);

  free(data);
  return 0;
}
