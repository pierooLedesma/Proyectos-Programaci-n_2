cmake_minimum_required(VERSION 4.0)
project(Parte2_Biblioteca)

set(CMAKE_CXX_STANDARD 20)

add_executable(Parte2_Biblioteca main.cpp
        Bibliotecas/Utils.hpp
        Bibliotecas/Libro.cpp
        Bibliotecas/Libro.hpp
        Bibliotecas/Espacio.cpp
        Bibliotecas/Espacio.hpp
        Bibliotecas/Estante.cpp
        Bibliotecas/Estante.hpp
        Bibliotecas/Biblioteca.cpp
        Bibliotecas/Biblioteca.hpp)
