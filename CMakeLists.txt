cmake_minimum_required(VERSION 3.25)

project(nlibc)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_library(${PROJECT_NAME}
  src/n_vector/vector_alloc.c
  src/n_vector/vector.c
  src/n_vector/vector_search.c
)

add_library(nlibc::nlibc ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(tester)

