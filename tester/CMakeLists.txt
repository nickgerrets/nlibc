project(test)

add_executable(${PROJECT_NAME}
	src/main.c
	src/vector.c
	src/hashmap.c
)

target_include_directories( ${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries( ${PROJECT_NAME}
	PRIVATE nlibc::nlibc
)

