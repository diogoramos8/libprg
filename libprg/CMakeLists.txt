cmake_minimum_required(VERSION 3.21)

# Add header files here manually
set(HEADERS
        "${CMAKE_CURRENT_LIST_DIR}/src/include/libprg/libprg.h"
)
# Add source files here manually
set(SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/src/libprg/fila.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/libprg/linear.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/libprg/pilha.c"
)

add_library(libprg
        src/libprg/pilha.c
        src/libprg/listas_encadeadas.c
        src/libprg/alg_ord_troca.c
        src/libprg/arvore.c
        src/libprg/arvore_avl.c)
target_sources(libprg PUBLIC ${SOURCES})
target_include_directories(libprg PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src/include)

target_compile_features(libprg PUBLIC c_std_17)

# https://cmake.org/cmake/help/latest/prop_tgt/AUTOGEN_TARGETS_FOLDER.html
source_group(
       TREE "${PROJECT_SOURCE_DIR}/libprg/src/include"
       PREFIX "Header Files"
       FILES ${HEADERS})

# https://cmake.org/cmake/help/latest/command/install.html
install(TARGETS libprg DESTINATION lib)
install(FILES ${HEADER_LIST} DESTINATION include)