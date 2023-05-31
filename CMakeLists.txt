cmake_minimum_required(VERSION 3.2)
project(base64)

set(CMAKE_CXX_STANDARD 14)

# Создание статической библиотеки
add_library(base64lib_static STATIC base64lib.cpp)
target_include_directories(base64lib_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Создание динамической библиотеки
add_library(base64lib_shared SHARED base64lib.cpp)
target_include_directories(base64lib_shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Установка целей и их свойств
set_target_properties(base64lib_static PROPERTIES OUTPUT_NAME "base64lib")
set_target_properties(base64lib_shared PROPERTIES OUTPUT_NAME "base64lib")

# Установка публичного API для библиотеки
target_include_directories(base64lib_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(base64lib_shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Установка импортируемых библиотек для динамической сборки
if (UNIX)
    target_link_libraries(base64lib_shared PUBLIC dl)
endif()

# Установка правил установки
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)

# Установка целей
install(TARGETS base64lib_static DESTINATION lib)
install(TARGETS base64lib_shared DESTINATION lib)
install(FILES base64lib.h DESTINATION include)
