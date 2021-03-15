cmake_minimum_required(VERSION 3.16)

project (maths1)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB MATHS_SRCS
     "src/*.cpp"
)

include_directories(include)

#add_compile_options(-Werror)
add_compile_options(-pedantic-errors)
add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-O2)
add_compile_options(-Wcast-align)
add_compile_options(-Wcast-qual)
add_compile_options(-Wctor-dtor-privacy)
add_compile_options(-Wduplicated-branches)
add_compile_options(-Wduplicated-cond)
add_compile_options(-Wextra-semi)
add_compile_options(-Wfloat-equal)
add_compile_options(-Wlogical-op)
add_compile_options(-Wnon-virtual-dtor)
add_compile_options(-Wold-style-cast)
add_compile_options(-Woverloaded-virtual)
add_compile_options(-Wredundant-decls)
#add_compile_options(-Wsign-conversion)
add_compile_options(-Wsign-promo)

find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)

add_executable (${PROJECT_NAME} ${MATHS_SRCS})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-system sfml-window X11 Xrandr Xcursor)
# yaml-cpp)
