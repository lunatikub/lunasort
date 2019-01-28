#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <curses.h>

#include "displayer.h"

/**
 *    0
 * 0 +--------> X
 *   |
 *   |
 *   |
 *   v
 *
 *   Y
 */

#define RED     (1)
#define GREEN   (2)
#define YELLOW  (3)
#define BLUE    (4)
#define MAGENTA (5)
#define CYAN    (6)
#define WHITE   (7)

#define COLOR(color, instr)                     \
  do {                                          \
    attron(COLOR_PAIR(color));                  \
    instr;                                      \
    attroff(COLOR_PAIR(color));                 \
  } while (0)

static void disp_refresh(void)
{
  mvprintw(0, 0, " ");
  refresh();
  if (T == 0) {
    getchar();
  } else {
    usleep(T);
  }
}

#define CELL_WIDTH  (4)
#define MAIN_ORIG_X (10)
#define MAIN_ORIG_Y (30)
#define ALGO_MARGIN (5)
#define ITER_MARGIN (50)

#define Y(y) ((y) + MAIN_ORIG_Y)
#define X(x) ((x) + MAIN_ORIG_X)

/**
 * Array section.
 */

static void disp_main_array_deco(int y, size_t sz)
{
  mvprintw(Y(y), X(0), "+---");
  for (size_t i = 1; i < sz; ++i) {
    mvprintw(Y(y), X(i * CELL_WIDTH), "+---");
  }
  mvprintw(Y(y), X((sz) * CELL_WIDTH), "+");
}

void disp_array(uint32_t *ptr, size_t sz)
{
  mvprintw(Y(1), X(0), "|");
  for (size_t i = 0; i < sz; ++i) {
    mvprintw(Y(1), X(i * CELL_WIDTH), "|%3u|", i);
    mvprintw(Y(3), X(i * CELL_WIDTH), "|   |", ptr[i]);
    attron(COLOR_PAIR(6));
    mvprintw(Y(3), X(i * CELL_WIDTH + 1), "%3u", ptr[i]);
    attroff(COLOR_PAIR(6));
  }
  disp_refresh();
}

/**
 * Algorithm section.
 * display lines: [0 - 30]
 */

void disp_algo_code(int line, const char *algo)
{
  mvprintw(line, ALGO_MARGIN, "%s", algo);
}

void disp_algo_cursor(int line)
{
  for (int i = 1; i < 30; ++i) {
    mvprintw(i, ALGO_MARGIN - 4, "   ");
  }
  COLOR(MAGENTA,
  {
    mvprintw(line, ALGO_MARGIN - 4, "-->");
  });
  disp_refresh();
}

/**
 * Operation section.
 * display lines: Y([-4 - -1]).
 */

static void disp_op_clean(void)
{
  for (int i = X(0); i < X(42 * CELL_WIDTH); ++i) {
    mvprintw(Y(-4), i, " ");
    mvprintw(Y(-3), i, " ");
    mvprintw(Y(-2), i, " ");
    mvprintw(Y(-1), i, " ");
  }
}

static void disp_op_name(const char *op_name)
{
  COLOR(YELLOW,
  {
    mvprintw(Y(-4), X(0), "operation: %s", op_name);
  });
}

void disp_op_swap(uint32_t *ptr, uint32_t a, uint32_t b)
{
  disp_op_clean();
  disp_op_name("swap");

  COLOR(YELLOW,
  {
    mvprintw(Y(3), X(a * CELL_WIDTH + 1), "%3u", ptr[a]);
    mvprintw(Y(3), X(b * CELL_WIDTH + 1), "%3u", ptr[b]);
    mvprintw(Y(-2), X(a * CELL_WIDTH + 2), "|");
    mvprintw(Y(-1), X(a * CELL_WIDTH + 2), "v");
    for (int i = X(a * CELL_WIDTH + 3); i < X(b * CELL_WIDTH + 2); ++i) {
      mvprintw(Y(-3), i, "_");
    }
    mvprintw(Y(-2), X(b * CELL_WIDTH + 2), "|");
    mvprintw(Y(-1), X(b * CELL_WIDTH + 2), "v");
  });
  disp_refresh();
}

void disp_op_lt(uint32_t *ptr, uint32_t a, uint32_t b)
{
  disp_op_clean();
  disp_op_name("less than");

  COLOR(YELLOW,
  {
    mvprintw(Y(3), X(a * CELL_WIDTH + 1), "%3u", ptr[a]);
    mvprintw(Y(3), X(b * CELL_WIDTH + 1), "%3u", ptr[b]);
    mvprintw(Y(-2), X(0), "%2u < %2u ?: %s",
             ptr[a], ptr[b], ptr[a] < ptr[b] ? "true" : "false");
  });
  disp_refresh();
}


/**
 * Variables section.
 * display ines: [5-6].
 */

#define NR_MAX_VAR (256)

struct var {
  uint32_t id;
  char *name;
  size_t value;
  int color;
} vars[NR_MAX_VAR];

static uint32_t nr_var;

static void disp_var_deco(void)
{
  mvprintw(1, ITER_MARGIN, "+------+-------+");
  mvprintw(2, ITER_MARGIN, "| name | value |");
  mvprintw(3, ITER_MARGIN, "+------+-------+");
}

void disp_var_add(uint32_t id, const char *name)
{
  assert(nr_var < NR_MAX_VAR);

  vars[nr_var].id = id;
  vars[nr_var].name = strdup(name);
  vars[nr_var].color = id % WHITE;
  ++nr_var;
}

static struct var* disp_var_find(uint32_t id)
{
  for (uint32_t i = 0; i < nr_var; ++i) {
    if (vars[i].id == id) {
      return &vars[i];
    }
  }
  return NULL;
}

static void disp_var_clean(void)
{
  for (int i = X(0); i < X(42 * CELL_WIDTH); ++i) {
    mvprintw(Y(5), i, " ");
    mvprintw(Y(6), i, " ");
  }
}

static void disp_var_refresh(void)
{
  struct var *iter;
  uint32_t y = 1;

  disp_var_clean();

  for (iter = &vars[0]; iter->name != NULL; ++iter) {
    attron(COLOR_PAIR(iter->color));
    mvprintw(y * 2 + 2, ITER_MARGIN, "| %4s | %5u |",
             iter->name, iter->value);
    mvprintw(y * 2 + 3, ITER_MARGIN, "+------+-------+");
    mvprintw(Y(5), X(iter->value * CELL_WIDTH + 2), "^");
    mvprintw(Y(6), X(iter->value * CELL_WIDTH + 2), "|");
    attroff(COLOR_PAIR(iter->color));
    ++y;
  }
}

void disp_var_update(uint32_t id, size_t value)
{
  struct var *var = disp_var_find(id);
  assert(var != NULL);
  var->value = value;
  disp_var_refresh();
}

/**
 * Main section
 **/

static void disp_deco(size_t sz)
{
  disp_main_array_deco(0, sz);
  disp_main_array_deco(2, sz);
  disp_main_array_deco(4, sz);
  disp_var_deco();
}

void disp_start(size_t sz)
{
  initscr();
  start_color();

  init_pair(RED, COLOR_RED, COLOR_BLACK);
  init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
  init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
  init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
  init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
  init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);

  disp_deco(sz);
}

void disp_stop(void)
{
  getchar();
  endwin();
}
