ast_dump_src = files(
    'ast_dump.c',
)

ast_dump = executable(
  'ast_dump',
  common_src,
  ast_dump_src,
  algo_src,
  utils_src,
  include_directories: [
    lunasort_inc,
    algo_test_inc,
  ],
  c_args: common_args,
)