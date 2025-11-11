cmake_minimum_required(VERSION 4.0)
project(Parte_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Parte_2 main.cpp
        Bibliotecas/Bebida.cpp
        Bibliotecas/Bebida.hpp
        Bibliotecas/Utils.hpp
        Bibliotecas/Producto.cpp
        Bibliotecas/Producto.hpp
        Bibliotecas/Cola.cpp
        Bibliotecas/Cola.hpp
        Bibliotecas/Nodo.cpp
        Bibliotecas/Nodo.hpp
        Bibliotecas/DetalleComanda.cpp
        Bibliotecas/DetalleComanda.hpp
        Bibliotecas/Entrada.cpp
        Bibliotecas/Entrada.hpp
        Bibliotecas/PlatoFondo.cpp
        Bibliotecas/PlatoFondo.hpp
        Bibliotecas/Restaurante.cpp
        Bibliotecas/Restaurante.hpp)
