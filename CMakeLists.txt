# Настройка проекта
cmake_minimum_required(VERSION 3.10)
project(lab02)
set(CMAKE_CXX_STANDARD 14)  # Добавление этой строки

# Добавление папки с тестами
add_subdirectory(gtests)

# Добавление исполняемого файла для основного приложения
add_executable(lab02 main.cpp)
target_include_directories(lab02 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# cmake_minimum_required(VERSION 3.10)
# project(lab02 VERSION 0.1.0 LANGUAGES C CXX)
# # Установка стандарта C++
# set(CMAKE_CXX_STANDARD 17)
# set(CXX_STANDARD_REQUIRED TRUE)
# # Добавление исполняемого файла lab02
# add_executable(lab02 main.cpp)
# enable_testing()
# add_subdirectory(gtests)
