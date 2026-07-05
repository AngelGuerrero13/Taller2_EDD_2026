#include "ArbolAVL.hpp"

ArbolAVL::ArbolAVL(){
    raiz = nullptr;
}

ArbolAVL::~ArbolAVL(){
    limpiar(raiz);
}

void ArbolAVL::limpiar(NodoAVL* nodo){

    if(nodo != nullptr){

        limpiar(nodo->getIzquierdo());
        limpiar(nodo->getDerecho());
        delete nodo;

    }
}

int ArbolAVL::altura(NodoAVL* altura){

    if(altura == nullptr){
        return 0;
    }

    return altura->getAltura();

}

int ArbolAVL::max(int a, int b){

    if(a > b){
        return a;
    } else {
        return b;
    }
}

NodoAVL* ArbolAVL::rotacionDerecha(NodoAVL* der){

    NodoAVL* x = der->getIzquierdo();
    NodoAVL* temp = x->getDerecho();

    x->setDerecho(der);
    der->setDerecho(temp);

    der->setAltura(max(altura(der->getIzquierdo()), altura(der->getDerecho()))+1);
    x->setAltura(max(altura(x->getIzquierdo()), altura(x->getDerecho()))+1);

    return x;
}

NodoAVL* ArbolAVL::rotacionIzquierda(NodoAVL* izq){

    NodoAVL* y = izq->getDerecho();
    NodoAVL* temp = y->getIzquierdo();

    y->setIzquierdo(izq);
    izq->setDerecho(temp);

    izq->setAltura(max(altura(izq->getIzquierdo()), altura(izq->getDerecho()))+1);
    y->setAltura(max(altura(y->getIzquierdo()), altura(y->getDerecho()))+1);

    return y;
}

int ArbolAVL::obtenerBalance(NodoAVL* N){

    if(N == nullptr){
        return 0;
    }

    return altura(N->getIzquierdo()) - altura(N->getDerecho());
}

void ArbolAVL::insertarCancion(Cancion* cancion){
    raiz = insertar(raiz, cancion);
}


NodoAVL* ArbolAVL::insertar(NodoAVL* nodo, Cancion* cancion){
    
    if(nodo == nullptr){
        return new NodoAVL(cancion);
    }
    
    if(cancion->getNombreCancion() < nodo->getCancion()->getNombreCancion()){
        
        nodo->setIzquierdo(insertar(nodo->getIzquierdo(), cancion));
        
    }else if(cancion->getNombreCancion() > nodo->getCancion()->getNombreCancion()) {

        nodo->setDerecho(insertar(nodo->getDerecho(), cancion));

    } else {
        return nodo;
    }

    nodo-> setAltura(1 + max(altura(nodo->getIzquierdo()), altura(nodo->getDerecho())));

    nodo->setAltura(1 + max(altura(nodo->getIzquierdo()), altura(nodo->getDerecho())));

    int balance = obtenerBalance(nodo);

    if (balance > 1 && cancion->getNombreCancion() < nodo->getIzquierdo()->getCancion()->getNombreCancion()){

        return rotacionDerecha(nodo);
    }

    if (balance < -1 && cancion->getNombreCancion() > nodo->getDerecho()->getCancion()->getNombreCancion()){

        return rotacionIzquierda(nodo);
    }

    if (balance > 1 && cancion->getNombreCancion() > nodo->getIzquierdo()->getCancion()->getNombreCancion()) {
        nodo->setIzquierdo(rotacionIzquierda(nodo->getIzquierdo()));
        return rotacionDerecha(nodo);
    }
    
    if (balance < -1 && cancion->getNombreCancion() < nodo->getDerecho()->getCancion()->getNombreCancion()) {
        nodo->setDerecho(rotacionDerecha(nodo->getDerecho()));
        return rotacionIzquierda(nodo);
    }

    return nodo; 
}

void ArbolAVL::inOrden(NodoAVL* nodo, ListaCancion* resultados){

    if(nodo != nullptr){
        inOrden(nodo->getIzquierdo(), resultados);
        resultados->insertarFinal(nodo->getCancion());
        inOrden(nodo->getDerecho(), resultados);
    }
}

ListaCancion* ArbolAVL::obtenerCancionesOrdenadas(){
    ListaCancion* resultados = new ListaCancion();
    inOrden(raiz, resultados);
    return resultados;
}