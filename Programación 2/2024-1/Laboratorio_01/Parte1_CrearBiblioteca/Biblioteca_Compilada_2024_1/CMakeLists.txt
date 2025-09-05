cmake_minimum_required(VERSION 4.0)
project(Biblioteca_Compilada_2024_1)

set(CMAKE_CXX_STANDARD 20)

add_library(Bibioteca_Compilada_2024_1 STATIC Biblioteca/Sobrecargas.cpp)

add_executable(Biblioteca_Compilada_2024_1 main.cpp)

target_link_libraries(Biblioteca_Compilada_2024_1 Bibioteca_Compilada_2024_1)