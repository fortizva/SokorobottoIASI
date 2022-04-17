#ifndef TABLERO_H_
#define TABLERO_H_

#include "celda.h"

const int MAX=10;
typedef celda TVectorTablero[MAX][MAX];

enum Direccion {
	A, B, I, D, IA, IB, II, ID, EA, EB, EI, ED
};

struct Tab {
	TVectorTablero vTablero;
	int ocupadas;
	int tam;
};

//PRE:{m inicializado correctamente,0<tam<MAX}
//POST:{inicia el tablero t a partir de los valores de la matriz m}
//Compejidad: O(n)²
void iniciarMatriz(Tab &t,celda m[MAX][MAX], int tam);

//PRE:{valor>0,fila>=0,col>=0}
//POST:{inserta el valor de una nueva casilla en la posicion fila col}
//Compejidad: O(1)
void insertar(Tab &t, celda::TipoCasilla valor,int fila, int col);

//PRE:{fila>=0,col>=0}
//POST:{vacia la casilla en la posicion fila col}
//Compejidad: O(1)
void borrar(Tab &t, int fila, int col);

//PRE:{fila>=0,col>=0}
//POST:{vacia la casilla en la posicion fila col}
//Compejidad: O(1)
bool estaVacia(Tab t, int fila, int col);

//PRE:{t inicializada correctamente,fila>=0,col>=0}
//POST:{devuelve el valor de la casilla en la posicion fila col}
//Compejidad: O(1)
int obtenerValorCasilla(Tab t, int fila, int col);

void mostrarMatriz(Tab t);

bool moverRobot(Tab &t, Direccion dir);

float calcularH(Tab &t);

// PRE:{t está inicializada correctamente}
// POST: {Devuelve 'true' si el tablero está en una situación de fin de juego}
// 
bool isFin(Tab t);

#endif /* TABLERO_H_ */
