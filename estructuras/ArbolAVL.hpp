#pragma once
#include "../clases/Cancion.hpp"
#include "ListaCancion.hpp"
#include "NodoAVL.hpp"
using namespace std;

class ArbolAVL {
    private:
        NodoAVL* raiz;

        int altura(NodoAVL* altura);
        int max(int a, int b);
        NodoAVL* rotacionDerecha(NodoAVL* der);
        NodoAVL* rotacionIzquierda(NodoAVL* izq);
        int obtenerBalance(NodoAVL* N);
        NodoAVL* insertar(NodoAVL* nodo, Cancion* cancion);
        void inOrden(NodoAVL* nodo, ListaCancion* resultados);
        void limpiar(NodoAVL* nodo);

    public:
        ArbolAVL();

        void insertarCancion(Cancion* cancion);

        ListaCancion* obtenerCancionesOrdenadas();

        ~ArbolAVL();
    };