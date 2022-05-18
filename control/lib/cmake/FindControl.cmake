# Folder donde esta la librería
set(CONTROL_ROOT ${CMAKE_SOURCE_DIR})
set(FIND_CONTROL_PATHS "${CONTROL_ROOT}/control")

# Project files
file(GLOB project_files "${FIND_CONTROL_PATHS}/include/*.h")
set(include_files "")
foreach(full_filename ${project_files})
    get_filename_component(filename ${full_filename} NAME)
    list(APPEND include_files ${filename})
endforeach()

# Folder donde es encuentra la cabecera
find_path(CONTROL_INCLUDE_DIR ${include_files}
        PATH_SUFFIXES include
        PATHS ${FIND_CONTROL_PATHS})

# Folder donde se encuentra el archivo binario
IF(MINGW)
    set(CONTROL_NAME "libcontrol")
ELSEIF(MSVC)
    set(CONTROL_NAME "control")
ELSEIF(UNIX)
    set(CONTROL_NAME "libcontrol")
ENDIF()
find_library(CONTROL_LIBRARY
        NAMES ${CONTROL_NAME}
        PATH_SUFFIXES lib
        PATHS ${FIND_CONTROL_PATHS})

message("Control Files: ${include_files}")
message("Control Name: ${CONTROL_NAME}")
message("Control PATH: ${FIND_CONTROL_PATHS}")
message("Control LIBRARY: ${CONTROL_LIBRARY}")
