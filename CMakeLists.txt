cmake_minimum_required(VERSION 3.5.0)

set(CMAKE_CXX_STANDARD 17)

project(AdventOfCode VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG        master # You can use a specific tag or commit hash here
)

FetchContent_MakeAvailable(fmt)

add_executable(AdventOfCode src/main.cpp)

target_link_libraries(AdventOfCode PRIVATE fmt::fmt)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
