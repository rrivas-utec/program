cmake_minimum_required(VERSION 3.20)
project(model)

set(CMAKE_CXX_STANDARD 17)

# Project files
file(GLOB project_files src/*.cpp)

# Project
add_library(${PROJECT_NAME} ${project_files})
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Listando directorios
message(${PROJECT_BINARY_DIR}/${PROJECT_NAME}.lib)
message(${PROJECT_SOURCE_DIR}/lib)

# Copiando directorio a librería
IF(MINGW)
    set(BINARY_FILE_NAME lib${PROJECT_NAME}.a)
ELSEIF(MSVC)
    set(BINARY_FILE_NAME ${PROJECT_NAME}.lib)
ENDIF()

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND copy ${PROJECT_BINARY_DIR}/${BINARY_FILE_NAME} ${PROJECT_SOURCE_DIR}/lib/${BINARY_FILE_NAME})
