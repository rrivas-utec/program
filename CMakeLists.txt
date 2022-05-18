cmake_minimum_required(VERSION 3.20)
project(program)

set(CMAKE_CXX_STANDARD 17)

# Agregar un nuevo modulo
set (MODULE_PATH ${CMAKE_SOURCE_DIR})
list(APPEND CMAKE_MODULE_PATH "${MODULE_PATH}/ui_control/lib/cmake")

IF(MINGW)
    set(SFML_ROOT "C:/SFML/mingw/SFML-2.5.1")
ELSEIF(MSVC)
    set(SFML_ROOT "C:/SFML/vs/64bit/SFML-2.5.1")
ENDIF()
set(SFML_DIR "${SFML_ROOT}/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)

# Buscar un nuevo paquete
find_package(ui_control REQUIRED)
find_package(SFML COMPONENTS graphics audio REQUIRED)

# Incluir un nuevo directorio (include)
include_directories(${UI_CONTROL_INCLUDE_DIR})

# Generar ejecutable e incluir library
message("Control LIBRARY: ${UI_CONTROL_LIBRARY}")
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${UI_CONTROL_LIBRARY} sfml-graphics sfml-audio)

add_subdirectory(ui_control)
add_subdirectory(model)