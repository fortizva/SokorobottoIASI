#include "Nodo.h"
#include <iostream>
#include <cstdlib>
#include "Lista.h"

using namespace std;


Nodo::Nodo(){
	this->valorh=9999;
	this->oper=new Lista();
	this->A=NULL;
}

Nodo::Nodo(Tab t_, float valorh_, Nodo *A_,TABLERO_H_::Direccion _id){
	this->t=t_;
	this->valorh=valorh_;
	this->A=A_;
	this->id=_id;
	this->oper=new Lista();
}


void Nodo::setParametros(Tab t_, float valorh_, Nodo *A_,TABLERO_H_::Direccion _id){
	this->t=t_;
	this->valorh=valorh_;
	this->A=A_;
	this->id=_id;
	this->oper=new Lista();
}


int Nodo::getValorh(){
	return this->valorh;
}

Nodo* Nodo::Padre(){
	return this->A;
}

void Nodo::setHijo(Nodo opera){
	oper->insertar(opera);
}

void Nodo::getHijo(Lista *hijos){
	hijos=this->oper;
}

TABLERO_H_::Direccion Nodo::getId(){
	return this->id;
}

void Nodo::generarHijos()
{
	int fila = this ->t.robotCoord.y;
	int col = this->t.robotCoord.x;
	// Caso A
	if (fila > 0 && obtenerValorCasilla(this ->t, fila - 1, col) == celda::AIRE && !ocupado(this ->t, fila - 1, col))
	{
		Nodo aux(this ->t, this ->t.vTablero[fila - 1][col].obtenerValorR(), this, TABLERO_H_::Direccion::A);
		aux.t.robotCoord.y--;
		this ->setHijo(aux);
	}

	// Caso B
	if (fila < this ->t.tam - 1 && obtenerValorCasilla(this ->t, fila + 1, col) == celda::AIRE && !ocupado(this ->t, fila + 1, col))
	{
		Nodo aux(this ->t, this ->t.vTablero[fila + 1][col].obtenerValorR(), this, TABLERO_H_::Direccion::B);
		aux.t.robotCoord.y++;
		this ->setHijo(aux);
	}

	// Caso I
	if (col > 0 && obtenerValorCasilla(this ->t, fila, col - 1) == celda::AIRE && !ocupado(this ->t, fila, col - 1))
	{
		Nodo aux(this ->t, this ->t.vTablero[fila][col - 1].obtenerValorR(), this, TABLERO_H_::Direccion::I);
		aux.t.robotCoord.x--;
		this ->setHijo(aux);
	}

	// Caso D
	if (col < this ->t.tam - 1 && obtenerValorCasilla(this ->t, fila, col + 1) == celda::AIRE && !ocupado(this ->t, fila, col + 1))
	{
		Nodo aux(this ->t, this ->t.vTablero[fila][col + 1].obtenerValorR(), this, TABLERO_H_::Direccion::D);
		aux.t.robotCoord.x++;
		this ->setHijo(aux);
	}

	/*// Caso IA			//Ya que tenemos que saber que en esa posicion esta la caja
	if (fila > 0 && ocupado(this ->t, fila - 1, col))
	{
		Nodo aux(this ->t, this ->t.vTablero[fila - 1][col].obtenerValorR(), this, TABLERO_H_::Direccion::IA);
		this ->setHijo(aux);
	}
	// Caso IB
	if (fila < this ->t.tam - 1 && ocupado(this ->t, fila + 1, col))
	{
		Nodo aux(this ->t, this ->t.vTablero[fila + 1][col].obtenerValorR(), this, TABLERO_H_::Direccion::IB);
		this ->setHijo(aux);
	}
	// Caso II
	if (col > 0 && ocupado(this ->t, fila, col - 1))
	{
		Nodo aux(this ->t, this ->t.vTablero[fila][col - 1].obtenerValorR(), this, TABLERO_H_::Direccion::II);
		this ->setHijo(aux);
	}
	// Caso ID
	if (col < this ->t.tam - 1 && ocupado(this ->t, fila, col + 1))
	{
		Nodo aux(this ->t, this ->t.vTablero[fila][col + 1].obtenerValorR(), this, TABLERO_H_::Direccion::ID);
		this ->setHijo(aux);
	}
	// Caso EA
	if (fila > 1 && ocupado(this ->t, fila - 1, col) && obtenerValorCasilla(this ->t, fila - 2, col) == celda::AIRE)
	{
		Nodo aux(this ->t, this ->t.vTablero[fila - 1][col].obtenerValorR(), this, TABLERO_H_::Direccion::EA);
		this ->setHijo(aux);
	}

	// Caso EB
	if (fila < this ->t.tam - 2 && ocupado(this ->t, fila + 1, col) && obtenerValorCasilla(this ->t, fila + 2, col) == celda::AIRE)
	{
		Nodo aux(this ->t, this ->t.vTablero[fila + 1][col].obtenerValorR(), this, TABLERO_H_::Direccion::EB);
		this ->setHijo(aux);
	}

	// Caso EI
	if (col > 1 && ocupado(this ->t, fila, col - 1) && obtenerValorCasilla(this ->t, fila, col - 2) == celda::AIRE)
	{
		Nodo aux(this ->t, this ->t.vTablero[fila][col - 1].obtenerValorR(), this, TABLERO_H_::Direccion::EI);
		this ->setHijo(aux);
	}
	// Caso ED
	if (col < this ->t.tam - 2 && ocupado(this ->t, fila, col + 1) && obtenerValorCasilla(this ->t, fila, col + 2) == celda::AIRE)
	{
		Nodo aux(this ->t, this ->t.vTablero[fila][col + 1].obtenerValorR(), this, TABLERO_H_::Direccion::ED);
		this ->setHijo(aux);
	}*/
}

Nodo::~Nodo(){
	//delete this;
}




