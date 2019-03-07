set(CMAKE_CXX_COMPILER_WORKS 1)
cmake_minimum_required(VERSION 2.8)
project(moduru)

set(CMAKE_CXX_STANDARD 17)

set(_src_root_path "${CMAKE_CURRENT_SOURCE_DIR}")
  
include_directories(${_src_root_path})

file(
    GLOB_RECURSE _source_list 
    LIST_DIRECTORIES false
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "${_src_root_path}/*.c*"
    "${_src_root_path}/*.cpp*"
    "${_src_root_path}/*.hpp*"
	"${_src_root_path}/*.hxx*"
)

add_library(moduru ${_source_list})
target_link_libraries(moduru ${CONAN_LIBS})

foreach(_source IN ITEMS ${_source_list})
    get_filename_component(_source_path "${_source}" PATH)
    string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
    source_group("${_source_path_msvc}" FILES "${_source}")
endforeach()
