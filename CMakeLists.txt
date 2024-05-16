cmake_minimum_required(VERSION 3.14)

project(Homework2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (TESTS_BUILD_TYPE MATCHES ASAN)
    set(COMPILE_OPTS -Wall -Wextra -Werror -pedantic -pedantic-errors -O1 -fsanitize=address -fno-omit-frame-pointer
            -fno-inline -fno-sanitize-recover=all)
    set(LINK_OPTS -fsanitize=address)
endif ()
if (TESTS_BUILD_TYPE MATCHES MSAN)
    set(COMPILE_OPTS -Wall -Wextra -Werror -pedantic -pedantic-errors -O1 -fsanitize=leak
            -fno-omit-frame-pointer
            -fno-sanitize-recover=all)
    set(LINK_OPTS -fsanitize=leak)
endif ()
if (TESTS_BUILD_TYPE MATCHES USAN)
    set(COMPILE_OPTS -Wall -Wextra -Werror -pedantic -pedantic-errors -O1
            -fsanitize=undefined,float-cast-overflow,float-divide-by-zero
            -fno-omit-frame-pointer -fno-sanitize-recover=all
            -fsanitize-recover=alignment)
    set(LINK_OPTS
            -fsanitize=undefined,float-cast-overflow,float-divide-by-zero)
endif ()

# Configure clang-tidy
if (${USE_CLANG_TIDY})
    set(CMAKE_CXX_CLANG_TIDY clang-tidy)
endif ()

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.5.4
)

FetchContent_MakeAvailable(Catch2)

add_subdirectory(libs)
add_subdirectory(test)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Exponential Expression)