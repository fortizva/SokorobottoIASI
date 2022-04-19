#ifndef ESIMPLE_H_
#define ESIMPLE_H_
#include "Tablero.h"
#include "Nodo.h"
#include "Lista.h"
#include <queue>

void escaladaSimple(Nodo nodo, queue<TABLERO_H_::Direccion> &sol);
void eSimpleRobot(Nodo nodo, queue<TABLERO_H_::Direccion> &sol);

#endif /* ESIMPLE_H_ */
