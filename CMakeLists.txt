cmake_minimum_required(VERSION 3.5)
project(multifile)
project(lab02 VERSION 0.0.14)
set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED TRUE)

add_executable(lab02 main.cpp functions.cpp)
target_include_directories(lab02 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (MSVC)
    add_compile_options(/W4 /WX)
    target_compile_options(lab02 PRIVATE
        /W4
    )
else ()
    add_compile_options(-Wall -Wextra -pedantic -Werror -g)
    target_compile_options(lab02 PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

enable_testing()
add_subdirectory(gtests)

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

# cmake_minimum_required(VERSION 3.5)
# project(multifile)
# project(lab02 VERSION 0.0.14)
# set(CMAKE_CXX_STANDARD 17)
# set(CXX_STANDARD_REQUIRED TRUE)
# add_executable(lab02 main.cpp functions.cpp)
# target_include_directories(lab02 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# if (MSVC)
#     add_compile_options(/W4 /WX)
#     target_compile_options(lab02 PRIVATE
#         /W4
#     )
# else ()
#     add_compile_options(-Wall -Wextra -pedantic -Werror -g)
#     target_compile_options(lab02 PRIVATE
#         -Wall -Wextra -pedantic -Werror
#     )
# endif()
# enable_testing()
# add_subdirectory(gtests)
# install(TARGETS lab02 RUNTIME DESTINATION bin)
# set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}") 
# if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
#     set(CPACK_GENERATOR DEB)
#     set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
# endif()
# if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
#     set(CPACK_GENERATOR ZIP)
#     set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
# endif()
# set(CPACK_PACKAGE_CONTACT example@example.com)
# include(CPack)
