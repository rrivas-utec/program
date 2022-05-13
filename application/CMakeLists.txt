cmake_minimum_required(VERSION 3.22)
project(application)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} src/library.cpp)

# Listando directorios
message(${PROJECT_BINARY_DIR}/${PROJECT_NAME}.lib)
message(${PROJECT_SOURCE_DIR}/lib)

# Copiando directorio a librería
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND copy ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.lib ${PROJECT_SOURCE_DIR}/lib/${PROJECT_NAME}.lib
)
