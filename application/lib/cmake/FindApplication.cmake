# Folder donde esta la librería
set(FIND_APPLICATION_PATHS "../..")

# Folder donde es encuentra la cabecera
find_path(APPLICATION_INCLUDE_DIR library.h
        PATH_SUFFIXES include
        PATHS ${FIND_APPLICATION_PATHS})

# Folder donde se encuentra el archivo binario
find_library(APPLICATION_LIBRARY
        NAMES application
        PATH_SUFFIXES lib
        PATHS ${FIND_APPLICATION_PATHS})
