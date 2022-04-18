#include "eSimple.h"

eSimple::eSimple()
{
}

void escaladaSimple(Nodo nodo, queue<TABLERO_H_::Direccion> &sol)
{
	// Comprobamos que no hemos llegado a una solución antes de continuar con la búsqueda
	if (!TABLERO_H_::isFin(nodo.t))
	{
		// Obtenemos los nodos hijos (movimientos) disponibles
		Nodo aux;
		nodo.oper->moverInicio();
		nodo.oper->consultar(aux);
		while (!nodo.oper->enFin())
		{
			// En caso de que el valor h sea mejor en el nodo hijo actual, cambiamos a dicho nodo y continuamos la búsqueda
			if (aux.getValorh() <= nodo.getValorh())
			{
				sol.push(aux.getId());
				nodo = aux;
				escaladaSimple(nodo, sol);
			}
			nodo.oper->avanzar();
			nodo.oper->consultar(aux);
		}
	}
}

eSimple::~eSimple()
{
}
