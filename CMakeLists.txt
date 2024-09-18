cmake_minimum_required(VERSION 3.10)

project(lab02)

# Add executable for main application
add_executable(lab02_cli main.cpp)

# Add library for functions
add_library(lab02 functions.cpp)

# Add executable for tests
add_executable(lab02_tests gtests/tests.cpp)

# Set common compiler flags
set_target_properties(lab02_cli lab02 lab02_tests PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

# Include directories for each target
target_include_directories(lab02_cli PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)
target_include_directories(lab02 PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)
target_include_directories(lab02_tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/gtests"
)

# Link lab02_cli with the lab02 library
target_link_libraries(lab02_cli PRIVATE lab02)

# Set compiler warnings for each target
if (MSVC)
    target_compile_options(lab02_cli PRIVATE /W4)
    target_compile_options(lab02 PRIVATE /W4)
    target_compile_options(lab02_tests PRIVATE /W4)
else ()
    target_compile_options(lab02_cli PRIVATE -Wall -Wextra -pedantic -Werror)
    target_compile_options(lab02 PRIVATE -Wall -Wextra -pedantic -Werror)
    target_compile_options(lab02_tests PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

# Add test for lab02_tests
enable_testing()
add_test(lab02_tests lab02_tests)

# If using Google Test, add the following:
# Find Google Test
# find_package(GTest REQUIRED)

# Link lab02_tests with Google Test library
target_link_libraries(lab02_tests gtest gtest_main)

# Include directories for Google Test
include_directories(${GTest_INCLUDE_DIR})


# cmake_minimum_required(VERSION 3.6.0)
# set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
# set(PROJECT_VESRION 0.0.${PATCH_VERSION})
# project(unittests VERSION ${PROJECT_VESRION})
# set(CMAKE_CXX_STANDARD 17)
# set(CXX_STANDARD_REQUIRED TRUE)
# set(CPACK_GENERATOR ZIP)
# set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
# set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
# set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
# include(CPack)
# add_subdirectory(gtests)
# enable_testing()
# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
