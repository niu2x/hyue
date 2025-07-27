cmake_minimum_required(VERSION 3.13.0 FATAL_ERROR)

include(GenerateExportHeader)

project(hyue VERSION 0.0.1 LANGUAGES CXX C)

option(HYUE_STATIC "build static lib" OFF)

if(HYUE_STATIC)
    add_library(hyue STATIC "")
    target_compile_definitions(hyue PUBLIC HYUE_STATIC_DEFINE)
else()
    add_library(hyue SHARED "")
    target_compile_definitions(hyue PRIVATE HYUE_EXPORTS)
endif()

set_target_properties(hyue PROPERTIES 
    CXX_STANDARD 17
    C_VISIBILITY_PRESET hidden
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
    POSITION_INDEPENDENT_CODE ON
)

file(GLOB cpp_src 
    src/*.cpp
    src/backend/OpenGL/*.cpp
    src/backend/Dummy/*.cpp
)

target_compile_definitions(hyue PRIVATE USE_OPENGL)

target_sources(hyue PRIVATE
    ${cpp_src}
)

target_include_directories(hyue PUBLIC
    include/
)

find_package(OpenGL REQUIRED)
target_link_libraries(hyue PUBLIC
    OpenGL::GL
)

# Install hyue
install(TARGETS hyue DESTINATION lib)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/hyue DESTINATION include)

add_subdirectory(Examples)