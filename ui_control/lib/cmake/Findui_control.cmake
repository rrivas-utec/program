# Folder donde esta la librería
set(UI_CONTROL_ROOT ${CMAKE_SOURCE_DIR})
set(FIND_UI_CONTROL_PATHS "${UI_CONTROL_ROOT}/ui_control")

# Project files
file(GLOB project_files "${FIND_UI_CONTROL_PATHS}/include/*.h")
set(include_files "")
foreach(full_filename ${project_files})
    get_filename_component(filename ${full_filename} NAME)
    list(APPEND include_files ${filename})
endforeach()

# Folder donde es encuentra la cabecera
find_path(UI_CONTROL_INCLUDE_DIR ${include_files}
        PATH_SUFFIXES include
        PATHS ${FIND_UI_CONTROL_PATHS})

# Folder donde se encuentra el archivo binario
IF(MINGW)
    set(UI_CONTROL_NAME "libui_control")
ELSEIF(MSVC)
    set(UI_CONTROL_NAME "ui_control")
ELSEIF(UNIX)
    set(UI_CONTROL_NAME "libui_control")
ENDIF()
find_library(UI_CONTROL_LIBRARY
        NAMES ${UI_CONTROL_NAME}
        PATH_SUFFIXES lib
        PATHS ${FIND_UI_CONTROL_PATHS})

message("Control Files: ${include_files}")
message("Control Name: ${UI_CONTROL_NAME}")
message("Control PATH: ${FIND_UI_CONTROL_PATHS}")
message("Control LIBRARY: ${UI_CONTROL_LIBRARY}")
