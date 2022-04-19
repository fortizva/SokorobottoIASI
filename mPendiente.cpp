#include "mPendiente.h"

void maximaPendiente(Nodo nodo, queue<TABLERO_H_::Direccion> &sol)
{
	// Comprobamos que no hemos llegado a una solución antes de continuar con la búsqueda
	if (!TABLERO_H_::isFin(nodo.t))
	{
		Nodo aux;
		Nodo auxMejor;

		// Obtenemos los nodos hijos (movimientos) disponibles
		nodo.oper->moverInicio();
		nodo.oper->consultar(aux);
		nodo.oper->consultar(auxMejor);
		// Seleccionamos el nodo hijo con mejor h
		while (!nodo.oper->enFin())
		{
			if (aux.getValorh() >= auxMejor.getValorh())
			{
				auxMejor = aux;
			}
		}
		// Si el nodo hijo es mejor que el actual ejecutamos el movimiento y continuamos con la búsqueda
		if (aux.getValorh() <= nodo.getValorh())
		{
			sol.push(aux.getId());
			nodo = aux;
			maximaPendiente(nodo, sol);
		}
	}
}