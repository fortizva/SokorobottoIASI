#include "Lista.h"
#include <cstdlib>


Lista::Lista () {
	inicio = NULL;
	fin    = NULL;
	pI     = NULL;
}


bool Lista::estaVacia () {
	return (inicio == NULL);
}


void Lista::moverInicio (){
	pI = inicio;
}


void Lista::moverFinal (){
	pI= fin;
}


void Lista::avanzar () {

	if (pI != NULL) {
		pI = pI->siguiente;
	}
}


void Lista::retroceder (){

	if (pI != inicio) {
		if (pI != NULL) {
			pI = pI->anterior;
		} else {
			pI = fin;
		}
	}
}


bool Lista::enInicio (){
	return (pI == inicio);
}


bool Lista::enFin (){
	return (pI == fin);
}


bool Lista::finLista (){
	return (pI == NULL);
}


void Lista::consultar (Nodo &dato){

	if (pI != NULL) {
		dato = pI->dato;
	}
}


void Lista::insertar (const Nodo &dato) {
	Nod *nuevo = new Nod (dato);	
	if (pI == NULL){
		if (estaVacia()) {
			nuevo->siguiente = pI;
			inicio = nuevo;
			fin    = nuevo;
		} else {
			nuevo->anterior = fin;
			fin->siguiente  = nuevo;
			fin = nuevo;
		}

	}
	else {
		if (pI->anterior == NULL) {
			inicio = nuevo;
			nuevo->siguiente = pI;
			nuevo->anterior = NULL;
			pI->anterior = nuevo;
		} else {
			nuevo->anterior  = pI->anterior;
			nuevo->siguiente = pI;
			(pI->anterior)->siguiente = nuevo;
			pI->anterior = nuevo;
		}
	}
	pI = nuevo;
}


void Lista::borrar () {

	Nod *pAux;

	if (!estaVacia() && !finLista()) {

		pAux=pI;

		if (pI == inicio) // El nodo a borrar es el primero
			inicio = inicio->siguiente;
		if (pI == fin)    // El nodo a borrar es el ultimo
			fin = fin->anterior;

		pI = pI->siguiente; // El PI apunta al siguiente

		if (pAux->anterior!=NULL)
			(pAux->anterior)->siguiente = pI;
		if (pAux->siguiente!=NULL)
			pI->anterior = pAux->anterior;

		delete pAux;
	}
}

Lista::~Lista() {
	moverInicio();
		while (!estaVacia())
			borrar();

	inicio = NULL;
	fin    = NULL;
	pI     = NULL;
}
