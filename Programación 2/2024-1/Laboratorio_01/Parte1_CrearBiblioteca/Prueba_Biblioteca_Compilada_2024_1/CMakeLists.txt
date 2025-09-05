cmake_minimum_required(VERSION 4.0)
project(Prueba_Biblioteca_Compilada_2024_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Prueba_Biblioteca_Compilada_2024_1 main.cpp
        Biblioteca/AperturaDeArchivos.hpp
        Biblioteca/Utils.h
        Biblioteca/Sobrecargas.hpp
        Biblioteca/Estructuras.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Biblioteca")

target_link_libraries(Prueba_Biblioteca_Compilada_2024_1 PRIVATE AperturaDeArchivos)

target_link_libraries(Prueba_Biblioteca_Compilada_2024_1 PRIVATE Bibioteca_Compilada_2024_1)