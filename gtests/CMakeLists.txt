include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Добавляем исполняемый файл для тестов
add_executable(tests tests.cpp "../functions.cpp")

# Указываем директории с заголовками
target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(tests PUBLIC gtest gtest_main)

# Добавляем тесты для CMake
enable_testing()
add_test(NAME tests COMMAND tests)


# include(FetchContent)
# FetchContent_Declare(
#     googletest
#     URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip

# )
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)
# set(COMMON_SRCS
#     "../functions.cpp"
# )
# add_executable(tests tests.cpp ${COMMON_SRCS})
# target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR})
# target_link_libraries(tests PUBLIC gtest gtest_main)
