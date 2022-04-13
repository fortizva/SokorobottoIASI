/*
 * celda.cpp
 *
 *  Created on: 13 abr 2022
 *      Author: ernes
 */

#include "celda.h"

celda::celda() {
	cordX = 0;
	cordY = 0;
	valorH = 0;
	tipo = 0;

}

celda::celda(int x, int y, int v, int t) {
	cordX = x;
	cordY = y;
	valorH = v;
	tipo = t;
}

void celda::ponerX(int x) {
	cordX = x;
}

int celda::obtenerX() {
	return cordX;
}

void celda::ponerY(int y) {
	cordY = y;
}

int celda::obtenerY() {
	return cordY;
}

void celda::ponerValor(int v) {
	valorH = v;
}

int celda::obtenerValor() {
	return valorH;
}

void celda::ponerTipo(int t) {
	tipo = t;
}

int celda::obtenerTipo() {
	return tipo;
}

celda::~celda() {
	// TODO Auto-generated destructor stub
}

