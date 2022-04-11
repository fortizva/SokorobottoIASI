#ifndef LISTA_H_
#define LISTA_H_

#include <iostream>
#include <cstdlib>

#include "Nodo.h"
using namespace std;

class Nodo;
class Lista {

	struct Nod {
	public:

		Nodo  dato;
		Nod     *siguiente;
		Nod     *anterior;

		Nod (const Nodo &dato) {
			this->dato      = dato;
			this->siguiente = NULL;
			this->anterior  = NULL;
		}
	};

	Nod *inicio;
	Nod *fin;
	Nod *pI;


public:

    /* DESC:   Crea una lista con punto de interes vacia
     * PRE:    -
     * POST:   Lista vacia
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)
*/
	Lista ();

     /*DESC:   Consulta si la lista esta vacia
     * PRE:    Lista creada
     * POST:   -
     * PARAM:  -
     * RET:    TRUE:  lista vacia
     *         FALSE: lista no vacia
     * COMP:   O(1)
     */
	bool  estaVacia ();

     /*DESC:   Coloca el PI al inicio de la lista
     * PRE:    Lista creada
     * POST:   PI apunta al primero elemento o a NULL si la lista esta vacia
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)
     */

	void  moverInicio ();

	 /*DESC:   Coloca el PI al final de la lista
     * PRE:    Lista creada
     * POST:   PI apunta al ultimo elemento o a NULL si la lista esta vacia
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)*/

	void  moverFinal ();

     /*DESC:   Coloca el PI apuntando al siguiente elemento de la lista
     * PRE:    Lista creada
     * POST:   PI apunta al siguiente elemento o a NULL si la lista esta vacia
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)*/

	void  avanzar ();

     /*DESC:   Coloca el PI apuntando al anterior elemento de la lista
     * PRE:    Lista creada
     * POST:   PI apunta al anterior elemento o a NULL si la lista esta vacia
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)*/

	void  retroceder ();

     /*DESC:   Consulta si el PI apunta al elemento inicial de la lista
     * PRE:    Lista creada
     * POST:   -
     * PARAM:  -
     * RET:    TRUE:  Si el PI apunta al primer elemento de la lista
     *         FALSE: Si el PI no apunta al primer elemento de la lista
     * COMP:   O(1)*/

	bool  enInicio ();

         /*DESC:   Consulta si el PI apunta al elemento inicial de la lista
     * PRE:    Lista creada
     * POST:   -
     * PARAM:  -
     * RET:    TRUE:  Si el PI apunta al ultimo elemento de la lista
     *         FALSE: Si el PI no apunta al ultimo elemento de la lista
     * COMP:   O(1)*/

	bool  enFin ();

     /*DESC:   Consulta si el PI apunta despues del ultimo elemento de la lista
     * PRE:    Lista creada
     * POST:   -
     * PARAM:  -
     * RET:    TRUE:  Si el PI apunta despues del ultimo elemento de la lista
     *         FALSE: Si el PI no apunta despues del ultimo elemento de la lista
     * COMP:   O(1)*/

	bool  finLista ();

     /*DESC:   Inserta un elemento en la lista, justo delante del PI
     * PRE:    Lista creada.
     * POST:   Lista con un elemento mas. PI apunta al elemento insertado.
     * PARAM:  E: dato -> Elemento a insertar
     * RET:    -
     * COMP:   O(1)*/

	void  insertar (const Nodo &dato);

	 /*DESC:   Devuelve el elemento de la lista apuntado por el PI
	 * PRE:    Lista creada.
	 * POST:   -
	 * PARAM:  S: dato -> Elemento apuntado por PI (si PI apunta a un elemento valido)
	 * RET:    -
	 * COMP:   O(1)*/

	void  consultar (Nodo &dato);

	 /*DESC:   Borra el elemento de la lista apuntado por el PI
	 * PRE:    Lista creada.
	 * POST:   Num. elementos en la lista disminuye en 1 si se puede borrar.
	 *         PI queda apuntando al siguiente elemento.
	 * PARAM:  -
	 * RET:    -
	 * COMP:   O(1)*/

	void  borrar ();

	 /*DESC:   Libera la memoria ocupada por los Nods de la lista
	 * PRE:    Lista creada.
	 * POST:   Num. elementos en la lista = 0. Lista vacia == TRUE
	 * PARAM:  -
	 * RET:    -
	 * COMP:   O(n)*/

     ~Lista();

};
#endif  /*LISTA_H_ */
