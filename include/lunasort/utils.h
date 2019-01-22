#ifndef UTILS_H__
#define UTILS_H__

#include <stdint.h>
#include <stdlib.h>

/**
 * Create an array with random values.
 * [ 42, 1, 5, 12, 27, 31, ...]
 */
uint32_t* array_random_create(size_t sz);

/**
 * Create an array sorted in ascending order.
 * [ 1, 2, 3, 4, 5, ... ]
 */
uint32_t* array_sorted_ascending_create(size_t sz);

/**
 * Create an array sorted in descending order.
 * [ 1, 2, 3, 4, 5, ... ]
 */
uint32_t* array_sorted_descending_create(size_t sz);

/**
 * Duplicate an array.
 */
uint32_t* array_duplicate(uint32_t *array, size_t sz);

#endif /* !UTILS_H__ */
