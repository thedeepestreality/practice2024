cmake_minimum_required(VERSION 3.28)

project(SfmlRotate)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SFML_DIR "C:\\repos\\SFML-2.6.2\\lib\\cmake\\SFML")

find_package(SFML 2.6.2 COMPONENTS graphics audio REQUIRED)

add_executable(rotate main.cpp)
target_compile_features(rotate PRIVATE cxx_std_17)
target_link_libraries(rotate PRIVATE sfml-graphics)
