cmake_minimum_required(VERSION 3.10) 
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(lab02 VERSION ${PROJECT_VESRION})

add_executable(lab02_cli main.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED TRUE)

target_link_libraries(lab02_cli PRIVATE
    lab02
)

if (MSVC) 
    target_compile_options(lab02_cli PRIVATE
        /W4
    )
    target_compile_options(lab02 PRIVATE
        /W4
    )
else ()
    target_compile_options(lab02_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS lab02_cli RUNTIME DESTINATION bin)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(CPACK_GENERATOR DEB)
endif()
if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(CPACK_GENERATOR ZIP)
endif()

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

# enable_testing()
# add_test(test_version test_version)