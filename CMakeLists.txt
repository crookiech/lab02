# Настройка проекта
cmake_minimum_required(VERSION 3.5)
project(lab02)
set(CMAKE_CXX_STANDARD 17)  # Добавление этой строки

# Добавление папки с тестами
add_subdirectory(gtests)

# Добавление исполняемого файла для основного приложения
add_executable(lab02 main.cpp functions.cpp)
target_include_directories(lab02 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
