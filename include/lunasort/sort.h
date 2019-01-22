#ifndef SORT_H__
#define SORT_H__

/**
 * Bubble sort.
 * Simple sorting algorithm that repeatedly steps through the list,
 * compares adjacent pairs and swaps them if they are in the wrong order.
 */
void bubble_sort(uint32_t *ptr, size_t sz);

void quick_sort(uint32_t *ptr, size_t sz);

#endif /* !SORT_H__ */
