cmake_minimum_required(VERSION 3.25)

project(nlibc)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_library(${PROJECT_NAME}
	src/n_buffer/buffer.c

	src/n_list/list_alloc.c
	src/n_list/list.c

	src/n_protect/protect.c

	src/n_stack/stack.c

	src/n_string/string_window.c
	src/n_string/string.c

	src/n_vector/vector_alloc.c
	src/n_vector/vector.c
	src/n_vector/vector_search.c

	src/macro_vector/macro_vector.c

)

add_library(nlibc::nlibc ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(tester)

