cmake_minimum_required(VERSION 3.10.0)
project(dpa25cup VERSION 0.1.0 LANGUAGES C)

add_executable(prog main.c)

add_compile_options(-fopenmp -lc)

include_directories(/opt/homebrew/Caskroom/miniforge/base/include/)

find_package(OpenMP REQUIRED)
if(OpenMP_C_FOUND)
    target_link_libraries(prog PUBLIC OpenMP::OpenMP_C)
endif()