cmake_minimum_required(VERSION 3.5)
project(lab02 VERSION 0.0.14) # Установите версию проекта

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(gtests)
add_executable(lab02 main.cpp functions.cpp)
target_include_directories(lab02 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (MSVC)
    target_compile_options(lab02 PRIVATE
        /W4
    )
else ()
    target_compile_options(lab02 PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS lab02 RUNTIME DESTINATION bin)

set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}") 

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(CPACK_GENERATOR DEB)
    set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
endif()

if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(CPACK_GENERATOR ZIP)
    set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
endif()

set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
