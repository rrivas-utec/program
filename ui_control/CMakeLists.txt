cmake_minimum_required(VERSION 3.20)
project(ui_control)

set(CMAKE_CXX_STANDARD 17)

# Project files
include_directories("./include")
file(GLOB project_files src/*.cpp)

IF(MINGW)
    set(SFML_ROOT "C:/SFML/mingw/SFML-2.5.1")
ELSEIF(MSVC)
    set(SFML_ROOT "C:/SFML/vs/64bit/SFML-2.5.1")
ENDIF()
set(SFML_DIR "${SFML_ROOT}/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)

# Buscar un nuevo paquete
find_package(SFML COMPONENTS graphics audio REQUIRED)

# Project
add_library(${PROJECT_NAME} ${project_files})
target_link_libraries(${PROJECT_NAME} ${UI_CONTROL_LIBRARY} sfml-graphics sfml-audio)
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
