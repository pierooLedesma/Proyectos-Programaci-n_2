cmake_minimum_required(VERSION 4.0)
project(Parte_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Parte_1 main.cpp
        Bibliotecas/Utils.hpp
        Bibliotecas/Producto.cpp
        Bibliotecas/Producto.hpp
        Bibliotecas/Bebida.cpp
        Bibliotecas/Bebida.hpp
        Bibliotecas/Entrada.cpp
        Bibliotecas/Entrada.hpp
        Bibliotecas/PlatoFondo.cpp
        Bibliotecas/PlatoFondo.hpp
        Bibliotecas/Nodo.cpp
        Bibliotecas/Nodo.hpp
        Bibliotecas/DetalleComanda.cpp
        Bibliotecas/DetalleComanda.hpp
        Bibliotecas/Cola.cpp
        Bibliotecas/Cola.hpp
        Bibliotecas/Restaurante.cpp
        Bibliotecas/Restaurante.hpp)
