lexer_dump_src = files(
    'lexer_dump.c',
)

lexer_dump = executable(
  'lexer_dump',
  common_src,
  lexer_dump_src,
  algo_src,
  utils_src,
  include_directories: [
    lunasort_inc,
    algo_test_inc,
  ],
  c_args: common_args,
)