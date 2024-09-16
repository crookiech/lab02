cmake_minimum_required(VERSION 3.5)
include(FetchContent)

# Скачивание и установка gtest
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Определение источников для тестирования
set(COMMON_SRCS
    "../functions.cpp"
    "../functions.h"
)

# Добавление исполняемого файла для тестов
add_executable(tests tests.cpp)

# Включение директории с исходными файлами
target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR})
target_include_directories(tests PUBLIC ${googletest_SOURCE_DIR}/googletest/include)

# Линковка библиотеки gtest
target_link_libraries(tests PUBLIC gtest gtest_main)
