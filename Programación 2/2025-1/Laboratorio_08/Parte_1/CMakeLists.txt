cmake_minimum_required(VERSION 4.0)
project(Parte_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Parte_1 main.cpp
        Bibliotecas/Dron.cpp
        Bibliotecas/Dron.hpp
        Bibliotecas/Utils.hpp
        Bibliotecas/DroneSemaforo.cpp
        Bibliotecas/DroneSemaforo.hpp
        Bibliotecas/DroneEstacionamiento.cpp
        Bibliotecas/DroneEstacionamiento.hpp
        Bibliotecas/DroneVelocidad.cpp
        Bibliotecas/DroneVelocidad.hpp
        Bibliotecas/Nodo.cpp
        Bibliotecas/Nodo.hpp
        Bibliotecas/Arbol.cpp
        Bibliotecas/Arbol.hpp
        Bibliotecas/Central.cpp
        Bibliotecas/Central.hpp)
