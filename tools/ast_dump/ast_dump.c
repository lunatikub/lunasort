#include <stdio.h>
#include <string.h>

#include <lunasort/utils/file.h>
#include <lunasort/utils/dot.h>

#include "parser.h"

#define STR_SIZE (256)

static uint32_t nr_vardec = 0;

static void ast_vardec_dump(struct ast_node *node, const char *previous)
{
  struct ast_vardec *vardec_node = ast_vardec_get(node);

  char vardec_id[STR_SIZE];
  snprintf(vardec_id, STR_SIZE, "vardec_%u", nr_vardec);

  char vardec_child[STR_SIZE];
  snprintf(vardec_child, STR_SIZE, "vardec_%u_child", nr_vardec);

  char vardec_label[STR_SIZE];
  snprintf(vardec_label, STR_SIZE, "id: %s, type: %s",
           vardec_node->name, vardec_node->type);

  dot_state(vardec_id, vardec_label, STATE_VARDEC);
  dot_state(vardec_child, "NULL", STATE_NULL);

  dot_edge(vardec_id, vardec_child, "child");
  dot_edge(previous, vardec_id, "next: vardec");

  ++nr_vardec;

  if (vardec_node->node.next != NULL) {
    ast_vardec_dump(vardec_node->node.next, vardec_id);
  }
}

static void ast_sort_dump(struct ast_node *node)
{
  struct ast_sort *sort_node = ast_sort_get(node);

  dot_state("sort", sort_node->name, STATE_SORT);
  ast_vardec_dump(sort_node->node.next, "sort");
}

static void ast_dump(struct ast_node *root_node)
{
  dot_state("root", "root", STATE_ROOT);
  dot_state("root_next", "NULL", STATE_NULL);
  ast_sort_dump(root_node->child);
  dot_edge("root", "sort", "child: sort");
  dot_edge("root", "root_next", "next");
}

int main(int argc, char **argv)
{
  if (argc != 2) {
    fprintf(stderr, "Usage: ./ast_dump algo.sort\n");
    return -1;
  }

  size_t len;
  char *sort = filetobuf(argv[1], &len);
  if (sort == NULL) {
    fprintf(stderr, "Error: open file %s.\n", argv[1]);
    return -1;
  }

  struct ast ast;
  algo_parse(&ast, sort, len);

  dot_start();
  ast_dump(&ast.root);
  dot_end();

  return 0;
}
