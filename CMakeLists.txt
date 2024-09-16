# Настройка проекта
cmake_minimum_required(VERSION 3.5)
project(lab02)
set(CMAKE_CXX_STANDARD 17)  # Добавление этой строки

# Добавление папки с тестами
add_subdirectory(gtests)

# Добавление исполняемого файла для основного приложения
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
