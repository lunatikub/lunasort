##############
## Lunasort ##
##############

# Declare the project
project(
  'lunasort',
  'c',
  'cpp',
  default_options : [
    'c_std=gnu11',
    '-std=gnu++11',
  ]
)

c_compiler = meson.get_compiler('c')
root_dir = meson.source_root()

thread_dep = dependency('threads')

##############################
## Dependencies/Subprojects ##
##############################

# create subprojects directory
run_command('mkdir', '-p', join_paths(root_dir, 'subprojects'))

wrap_file = {
  'gtest': [ '1.7.0', 'googletest-release-1.7.0' ],
}

foreach name, content : wrap_file
  r = run_command(join_paths(root_dir,
                             'tools',
                             'subproject_prerequisite.sh'),
                  name, content[0], content[1])
  if r.returncode() != 0
    error('subproject_prerequisite.sh')
  endif
endforeach

gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_dep')

ncurses_dep = c_compiler.find_library('ncurses')
rt_dep = c_compiler.find_library('rt')

###################
## Configuration ##
###################

conf_data = configuration_data()

conf_data.set('LUNASORT_VERSION', '"1.0"')
conf_data.set('LUNASORT_PROFILING', get_option('profiling'))

configure_file(
  input: join_paths(root_dir, 'include', 'lunasort', 'config.h.in'),
  output: 'config.h',
  configuration : conf_data
)

############################
## Flags compilation/link ##
############################

common_args = meson.get_compiler('c').get_supported_arguments([
  '-Wall',
  '-Werror',
  '-D_GNU_SOURCE',
  '-march=native',
  '-Wbool-compare',
  '-Wformat-security',
  '-Winit-self',
  '-Wlogical-op',
  '-Wtrampolines',
  '-Wmissing-format-attribute',
  '-Wno-error=deprecated-declarations',
  '-Wno-format-zero-length',
  '-pipe',
  '-g3',
  '-pthread',
  '-fstack-protector',
  '-funwind-tables',
  '-fasynchronous-unwind-tables',
  '-fstack-protector-strong',
  '-fno-common',
  '-Wshadow',
  '-Wmissing-declarations',
  '-Wpointer-arith',
  '-Wformat=2',
  '-mpclmul',
  '-msse4.1',
])

#############
## Include ##
#############

# Global namespace: #include <lunasort/...>
lunasort_inc = include_directories('include', '.')

#################
## Src + Tests ##
#################

subdir('src')
subdir('tests')

##############
## Lunasort ##
##############

lunasort = executable(
  'lunasort',
  common_src,
  lunasort_src,
  sort_src,
  include_directories: lunasort_inc,
  c_args: common_args,
  dependencies: [
    ncurses_dep,
  ]
)

##################
## Lunanimation ##
##################

lunanimation = executable(
  'lunanimation',
  common_src,
  lunanimation_src,
  sort_src,
  include_directories: lunasort_inc,
  c_args: common_args,
  dependencies: [
    ncurses_dep,
  ]
)
