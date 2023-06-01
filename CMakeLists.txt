cmake_minimum_required(VERSION 3.25)

project(nlibc)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_library(${PROJECT_NAME}
	src/buffer/buffer.c

	src/list/list_alloc.c
	src/list/list.c

	src/protect/protect.c

	src/stack/stack.c

	src/string/string_view.c
	src/string/string.c

	src/vector/vector_alloc.c
	src/vector/vector.c
	src/vector/vector_search.c

	src/hashmap/hashmap.c

	src/allocator/allocator.c
)

add_library(nlibc::nlibc ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(tester)

