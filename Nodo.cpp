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
}


void Nodo::setParametros(Tab t_, float valorh_, Nodo *A_,TABLERO_H_::Direccion _id){
	this->t=t_;
	this->valorh=valorh_;
	this->A=A_;
	this->id=_id;
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

Nodo::~Nodo(){
	//delete this;
}




