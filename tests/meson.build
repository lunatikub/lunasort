test_src = files(
  'test_sort.cc',
  'test_main.cc',
  # sort algorithms
  'test_bubble.cc',
  'test_insertion.cc',
)

unit_test = executable(
  'unit-test',
  test_src,
  common_src,
  sort_src,
  include_directories: [ lunasort_inc  ],
  c_args: common_args,
  cpp_args: common_args + [ '-std=gnu++11' ],
  dependencies: [
    gtest_dep,
    ncurses_dep,
  ]
)

run_target(
  'unit-test',
  command: [ unit_test.full_path() ],
  depends: unit_test,
)

test('unit-test', unit_test)
