test_algo_src = files(
  'test_algo.cc',
  'test_lexer.cc',
)

unit_test_algo = executable(
  'unit-test-algo',
  test_algo_src,
  algo_src,
  include_directories: [ algo_test_inc ],
  c_args: common_args,
  cpp_args: common_args + [ '-std=gnu++11' ],
  dependencies: [ gtest_dep ],
)

run_target(
  'unit-test-algo',
  command: [ unit_test_algo.full_path() ],
  depends: unit_test_algo,
)

test('unit-test-algo', unit_test_algo)
