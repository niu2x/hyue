cmake_minimum_required(VERSION 3.13.0 FATAL_ERROR)

include(GenerateExportHeader)

project(DrawingMoon VERSION 0.0.1 LANGUAGES CXX C)

add_library(DrawingMoonRT SHARED "")

generate_export_header(DrawingMoonRT
    BASE_NAME           DRAWING_MOON
    EXPORT_MACRO_NAME   DRAWING_MOON_API
    EXPORT_FILE_NAME    include/DrawingMoon/api.h
)

set_target_properties(DrawingMoonRT PROPERTIES 
    CXX_STANDARD 17
    C_VISIBILITY_PRESET hidden
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
    POSITION_INDEPENDENT_CODE ON
)

target_sources(DrawingMoonRT PRIVATE
    src/DrawingMoon.cpp
)

target_include_directories(DrawingMoonRT PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/include
    include/
)

# Install DrawingMoonRT
install(TARGETS DrawingMoonRT DESTINATION lib)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/DrawingMoon DESTINATION include)
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/DrawingMoon DESTINATION include)


add_subdirectory(Examples)