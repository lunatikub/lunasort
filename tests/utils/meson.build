test_utils_src = files(
  'test_utils.cc',
)

unit_test_utils = executable(
  'unit-test-utils',
  test_utils_src,
  utils_src,
  include_directories: [
    lunasort_inc,
    utils_test_inc,
  ],  
  c_args: common_args,
  cpp_args: common_args + [ '-std=gnu++11' ],
  dependencies: [ gtest_dep ],
)

run_target(
  'unit-test-utils',
  command: [ unit_test_utils.full_path() ],
  depends: unit_test_utils,
)

test('unit-test-utils', unit_test_utils)

configure_file(
  input: 'test.txt',
  output: 'test.txt',
  copy: true
)