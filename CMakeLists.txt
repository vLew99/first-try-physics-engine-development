cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
project(Collision LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# enable CTest
enable_testing()

FILE(GLOB SRCS src/*.c src/data_structures/*.c)

include_directories( ${PROJECT_SOURCE_DIR}/include )

link_libraries(m SDL2)

add_executable(
    ${PROJECT_NAME}
    tests/main.c
    ${SRCS}
    # tests/Vec2_LL.c
    # tests/polygon_test.c
    # tests/dynamics_test.c
    # tests/loop.c
    # tests/demo-sdl.c
)

target_compile_options(${PROJECT_NAME} PRIVATE -g -Werror -Wpedantic)
# target_compile_options(${PROJECT_NAME} PRIVATE -g -Werror)

# for specific targets
# target_include_directories(
    # ${PROJECT_NAME}
    # PRIVATE ${PROJECT_SOURCE_DIR}/include
# )
# target_link_libraries( ${PROJECT_NAME} m SDL2)

add_executable( linkedlisttest
    tests/Vec2_LL.c
    ${SRCS}
)

target_link_libraries( linkedlisttest check m rt subunit )

add_test(
    NAME test1
    COMMAND linkedlisttest
)
