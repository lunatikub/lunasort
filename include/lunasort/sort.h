#ifndef SORT_H__
#define SORT_H__

/**
 * Nomenclature suffix:
 * + '_o': optimized
 * + '_r'" recursive
 */

/**
 * Bubble sort.
 * https://en.wikipedia.org/wiki/Bubble_sort
 */
void bubble_sort(uint32_t *ptr, size_t sz);
void bubble_sort_o(uint32_t *ptr, size_t sz);

/**
 * Insertion sort.
 * https://en.wikipedia.org/wiki/Insertion_sort
 */
void insertion_sort(uint32_t *ptr, size_t sz);
void insertion_sort_o(uint32_t *ptr, size_t sz);
void insertion_sort_r(uint32_t *ptr, size_t sz);

#endif /* !SORT_H__ */
