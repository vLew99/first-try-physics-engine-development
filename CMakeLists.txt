cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
project(Collision LANGUAGES C)

add_executable(
	${PROJECT_NAME}
	# src/main.c
	src/collision.c
	src/utils.c
	src/vector_funcs.c
	src/polygon_funcs.c
	src/dynamics.c
	src/data_structures/linked_list.c
	

	# tests
	# tests/Vec2_LL.c
	# tests/polygon_test.c
	# tests/dynamics_test.c
	tests/loop.c
)

#target_compile_options(${PROJECT_NAME} PRIVATE -g -Werror -Wpedantic)
target_compile_options(${PROJECT_NAME} PRIVATE -g -Werror)



target_include_directories(
	${PROJECT_NAME}
	PRIVATE ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
	${PROJECT_NAME}
	m
)
