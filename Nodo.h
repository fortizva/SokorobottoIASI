#ifndef NODO_H_
#define NODO_H_
#include <iostream>
#include "Tablero.h"

using namespace std;
class Lista;
class Nodo{
public:
        float valorh;
        Tab t;
        TABLERO_H_::Direccion id;
        Nodo *A;
        Lista *oper;

    Nodo();

    Nodo(Tab t_, float valorh_, Nodo *A_,TABLERO_H_::Direccion _id);

    int getValorh();

    Nodo* Padre();

    void setHijo(Nodo opera);

    void getHijo(Lista *hijos);

    TABLERO_H_::Direccion getId();

    void setParametros(Tab t_, float valorh_, Nodo *A_,TABLERO_H_::Direccion _id);

    ~Nodo();




};
#endif /* NODO_H_*/

