cmake_minimum_required(VERSION 4.0)
project(Laboratorio_09)

set(CMAKE_CXX_STANDARD 20)

add_executable(Laboratorio_09 main.cpp
        Bibliotecas/Infraccion.cpp
        Bibliotecas/Infraccion.hpp
        Bibliotecas/Utils.hpp
        Bibliotecas/Vehiculo.cpp
        Bibliotecas/Vehiculo.hpp
        Bibliotecas/Multa.cpp
        Bibliotecas/Multa.hpp
        Bibliotecas/Empresa.cpp
        Bibliotecas/Empresa.hpp
        Bibliotecas/MinisterioDeTransporte.cpp
        Bibliotecas/MinisterioDeTransporte.hpp)
