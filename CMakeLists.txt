cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
project(Collision LANGUAGES C)

add_executable(
	${PROJECT_NAME}
	src/main.c
	src/collision.c
	src/utils.c
	src/vector_funcs.c
)

target_include_directories(
	${PROJECT_NAME}
	PRIVATE ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
	${PROJECT_NAME}
	m
)