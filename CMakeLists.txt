cmake_minimum_required(VERSION 3.6.0)
project(lab02)
include_directories(C:/programming/lab02/googletest/googletest/include)
link_directories(C:/programming/lab02/googletest/googletest/build/lib)

# target_link_libraries(gtest gtest_main)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем библиотеку и исполняемые файлы
add_library(lab02 functions.cpp)
add_executable(lab02_cli main.cpp)
add_executable(lab02_tests gtests/tests.cpp)

# Подключаем директории с заголовочными файлами
target_include_directories(lab02 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(lab02_cli PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(lab02_tests PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/gtests")

# Связываем библиотеки
target_link_libraries(lab02_cli PRIVATE lab02)
target_link_libraries(lab02_tests PRIVATE gtest gtest_main)

# Настройки компиляции для MSVC и GCC
if (MSVC)
    target_compile_options(lab02_cli PRIVATE /W4)
    target_compile_options(lab02 PRIVATE /W4)
    target_compile_options(lab02_tests PRIVATE /W4)
else ()
    target_compile_options(lab02_cli PRIVATE -Wall -Wextra -pedantic -Werror)
    target_compile_options(lab02 PRIVATE -Wall -Wextra -pedantic -Werror)
    target_compile_options(lab02_tests PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

# Включаем тестирование
enable_testing()
add_test(NAME lab02_tests COMMAND lab02_tests)


# cmake_minimum_required(VERSION 3.10)
# project(lab02)
# add_executable(lab02_cli main.cpp)
# add_library(lab02 functions.cpp)
# add_executable(lab02_tests gtests/tests.cpp)
# set_target_properties(lab02_cli lab02 lab02_tests PROPERTIES
#     CXX_STANDARD 14
#     CXX_STANDARD_REQUIRED ON
# )
# target_include_directories(lab02_cli PRIVATE
#     "${CMAKE_CURRENT_SOURCE_DIR}"
# )
# target_include_directories(lab02 PRIVATE
#     "${CMAKE_CURRENT_SOURCE_DIR}"
# )
# target_include_directories(lab02_tests PRIVATE
#     "${CMAKE_CURRENT_SOURCE_DIR}/gtests"
# )
# target_link_libraries(lab02_cli PRIVATE lab02)
# if (MSVC)
#     target_compile_options(lab02_cli PRIVATE /W4)
#     target_compile_options(lab02 PRIVATE /W4)
#     target_compile_options(lab02_tests PRIVATE /W4)
# else ()
#     target_compile_options(lab02_cli PRIVATE -Wall -Wextra -pedantic -Werror)
#     target_compile_options(lab02 PRIVATE -Wall -Wextra -pedantic -Werror)
#     target_compile_options(lab02_tests PRIVATE -Wall -Wextra -pedantic -Werror)
# endif()
# enable_testing()
# add_test(lab02_tests lab02_tests)
# target_link_libraries(lab02_tests gtest gtest_main)
# include_directories(${GTest_INCLUDE_DIR})
