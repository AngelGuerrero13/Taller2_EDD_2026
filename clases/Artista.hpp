#pragma once
#include <string>
#include "Cancion.hpp"
#include "../estructuras/ArbolAVL.hpp"

class Artista {
    private:
        string nombre;
        int reproduccionesTotales;
        ArbolAVL* canciones;
        Artista* siguiente;
    public:
        Artista(string nom);

        string getNombre();
        int getReproduccionesTotales();
        ArbolAVL* getCanciones();
        Artista* getSiguiente();

        void setReproduccionesTotales(int total);
        void setSiguiente(Artista* sig);

        void agregarCancion(Cancion* c);

        ~Artista();

};

