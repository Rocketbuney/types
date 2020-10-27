cmake_minimum_required(VERSION 3.12)
project(types_lib)

include_directories(include)
add_library(
  types
  src/linear_list.cpp
  include/types/types.h
  include/types/list.h
)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(deps/googletest/
                 EXCLUDE_FROM_ALL)

include_directories(include)
add_executable(
  unit_test
  test/main.cpp
)
target_link_libraries(unit_test LINK_PUBLIC types gtest_main)