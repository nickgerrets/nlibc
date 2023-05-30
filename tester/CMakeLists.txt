project(test)

add_executable(${PROJECT_NAME}
	src/main.c
	src/vector.c
	src/hashmap.c
	src/macro_vector.c
	src/lists.c
	src/buffer.c
)

target_include_directories( ${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries( ${PROJECT_NAME}
	PRIVATE nlibc::nlibc
)

