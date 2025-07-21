cmake_minimum_required(VERSION 3.13.0 FATAL_ERROR)

include(GenerateExportHeader)

project(DrawingMoon VERSION 0.0.1 LANGUAGES CXX C)

add_library(DrawingMoonRT SHARED "")

generate_export_header(DrawingMoonRT
    BASE_NAME           DRAW_MOON
    EXPORT_MACRO_NAME   DRAW_MOON_API
    EXPORT_FILE_NAME    include/DrawingMoon/api.h
)

set_target_properties(DrawingMoonRT PROPERTIES 
    CXX_STANDARD 17
    C_VISIBILITY_PRESET hidden
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
    POSITION_INDEPENDENT_CODE ON
)

file(GLOB_RECURSE cpp_src src/*.cpp)

target_sources(DrawingMoonRT PRIVATE
    ${cpp_src}
)

target_include_directories(DrawingMoonRT PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/include
    include/
)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
target_link_libraries(DrawingMoonRT PUBLIC
    glfw
    OpenGL::GL
)

# Install DrawingMoonRT
install(TARGETS DrawingMoonRT DESTINATION lib)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/DrawingMoon DESTINATION include)
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/DrawingMoon DESTINATION include)


add_subdirectory(Examples)