#ifndef ESIMPLE_H_
#define ESIMPLE_H_
#include "Tablero.h"
#include "Nodo.h"
#include "Lista.h"
#include <queue>

class eSimple
{
public:
	eSimple();
	void escaladaSimple(Nodo nodo, queue<TABLERO_H_::Direccion> &sol);
	virtual ~eSimple();
};

#endif /* ESIMPLE_H_ */
