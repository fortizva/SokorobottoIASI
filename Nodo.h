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
        string id;
        Nodo *A;
        Lista *oper;

    Nodo();

    Nodo(Tab t_, float valorh_, Nodo *A_,string _id);

    int getValorh();

    Nodo* Padre();

    void setHijo(Nodo opera);

    void getHijo(Lista *hijos);

    string getId();

    void setParametros(Tab t_, float valorh_, Nodo *A_,string _id);

    ~Nodo();




};
#endif /* NODO_H_*/

