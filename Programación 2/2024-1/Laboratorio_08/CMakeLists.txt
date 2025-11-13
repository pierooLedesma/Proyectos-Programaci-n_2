cmake_minimum_required(VERSION 4.0)
project(Laboratorio_08)

set(CMAKE_CXX_STANDARD 20)

add_executable(Laboratorio_08 main.cpp
        Bibliotecas/Libro.cpp
        Bibliotecas/Libro.hpp
        Bibliotecas/Utils.hpp
        Bibliotecas/Enciclopedia.cpp
        Bibliotecas/Enciclopedia.hpp
        Bibliotecas/Novela.cpp
        Bibliotecas/Novela.hpp
        Bibliotecas/Revista.cpp
        Bibliotecas/Revista.hpp
        Bibliotecas/Nodo.cpp
        Bibliotecas/Nodo.hpp
        Bibliotecas/Lista.cpp
        Bibliotecas/Lista.hpp
        Bibliotecas/Estante.cpp
        Bibliotecas/Estante.hpp
        Bibliotecas/Biblioteca.cpp
        Bibliotecas/Biblioteca.hpp
        Bibliotecas/AperturaDeLecturaYEscrituraArchivos.cpp
        Bibliotecas/AperturaDeLecturaYEscrituraArchivos.hpp)
