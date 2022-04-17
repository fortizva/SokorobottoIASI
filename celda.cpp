#include "celda.h"

celda::celda() {
	cordX = 0;
	cordY = 0;
	valorR = 9999;
	valorC = 9999;
	tipo = AIRE;

}

celda::celda(int x, int y, int vr, int vc, TipoCasilla t) {
	cordX = x;
	cordY = y;
	valorR = vr;
	valorC = vc;
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

void celda::ponerValorR(int v) {
	valorR = v;
}

int celda::obtenerValorR() {
	return valorR;
}

void celda::ponerValorC(int v) {
	valorC = v;
}

int celda::obtenerValorC() {
	return valorC;
}


void celda::ponerTipo(TipoCasilla t) {
	tipo = t;
}

celda::TipoCasilla celda::obtenerTipo() {
	return tipo;
}

celda::~celda() {
}

