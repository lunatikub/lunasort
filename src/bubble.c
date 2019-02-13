#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include <lunasort/sort.h>

#include "operation.h"
//#include "displayer.h"

void bubble_sort(uint32_t *ptr, size_t sz)
{
  for (size_t i = sz - 1; i > 0; --i) {
    for (size_t j = 0; j < i; ++j) {
      if (lt(ptr[j + 1], ptr[j])) {
        swap(&ptr[j + 1], &ptr[j]);
      }
    }
  }
}

void bubble_sort_o(uint32_t *ptr, size_t sz)
{
  for (size_t i = sz - 1; i > 0;--i) {
    bool swapped = set(true);
    for (size_t j = 0; j < i; ++j) {
      if (lt(ptr[j + 1], ptr[j])) {
        swap(&ptr[j + 1], &ptr[j]);
        swapped = set(false);
      }
    }
    if (eq(swapped, true)) {
      break;
    }
  }
}

// void bubble_sort_a(uint32_t *ptr, size_t sz)
// {
//   disp_start(sz);

//   disp_algo_code(1, "bubble_sort(T):");
//   disp_algo_code(2, "| for i = size(T) - 1 to 1");
//   disp_algo_code(3, "| | for j = 0 to i - 1");
//   disp_algo_code(4, "| | | if T[j + 1] < T[j]");
//   disp_algo_code(5, "| | | | swap(T[j + 1], T[j])");

// #define I_ID (1)
// #define J_ID (2)

//   disp_var_add(I_ID, "i");
//   disp_var_add(J_ID, "j");

//   disp_array(ptr, sz);
//   disp_algo_cursor(2);
//   for (size_t i = sz - 1; i > 0;--i) {
//     disp_var_update(I_ID, i);
//     disp_algo_cursor(3);
//     for (size_t j = 0; j < i; ++j) {
//       disp_var_update(J_ID, j);
//       disp_algo_cursor(4);
//       disp_op_lt(ptr, j + 1, j);
//       if (lt(ptr[j + 1], ptr[j])) {
//         disp_algo_cursor(5);
//         disp_op_swap(ptr, j, j + 1);
//         swap(&ptr[j + 1], &ptr[j]);
//       }
//       disp_array(ptr, sz);
//       disp_algo_cursor(3);
//     }
//     disp_algo_cursor(2);
//   }
//   disp_stop();

// #undef I_ID
// #undef J_ID
// }
