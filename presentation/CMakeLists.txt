cmake_minimum_required(VERSION 3.22)
project(presentation)

set(CMAKE_CXX_STANDARD 17)

# Agregar un nuevo modulo
list(APPEND CMAKE_MODULE_PATH "C:/Users/rudri/Documents/UTEC/CS1103 - New/Unit 5b/program/application/lib/cmake")
list(APPEND CMAKE_MODULE_PATH "C:/Users/rudri/DevLibraries/SFML/64bit/SFML-2.5.1/lib/cmake")

# Buscar un nuevo paquete
find_package(Application REQUIRED)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# Incluir un nuevo directorio (include)
include_directories(${APPLICATION_INCLUDE_DIR})

# Generar ejecutable e incluir library
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${APPLICATION_LIBRARY} sfml-graphics sfml-audio)
