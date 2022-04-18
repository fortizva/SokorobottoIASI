#ifndef MPENDIENTE_H_
#define MPENDIENTE_H_

#include "Lista.h"
#include "Tablero.h"
#include <queue>

class mPendiente
{
public:
	mPendiente();
	void maximaPendiente(Nodo nodo, queue<TABLERO_H_::Direccion> &sol);
	virtual ~mPendiente();
};

#endif /* MPENDIENTE_H_ */
