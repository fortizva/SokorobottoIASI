#ifndef TABLERO_H_
#define TABLERO_H_

#include "celda.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX=10;
typedef celda TVectorTablero[MAX][MAX];

enum Direccion {
	A, B, I, D, IA, IB, II, ID, EA, EB, EI, ED
};

struct Coordenada {
	int x;
	int y;
};

struct Tarea {
	Coordenada coord;
	Direccion task;
};

struct Tab {
	TVectorTablero vTablero;
	int ocupadas;
	int tam;
	Coordenada robotCoord;
	vector<Coordenada> cajas, metas;
	vector<Tarea> posiciones;
};


//PRE:{m inicializado correctamente,0<tam<MAX}
//POST:{inicia el tablero t a partir de los valores de la matriz m}
//Compejidad: O(n^2)
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

//bool moverRobot(Tab &t, Direccion dir);

// PRE: {t está inicializada correctamente y los datos de coordenadas de metas y posiciones objetivo están completos}
// POST: {Fija los valores de heurística en las casillas del tablero desde la perspectiva del robot (false) o de las cajas (true)}
// Complejidad: O(n^3)
void calcularH(Tab &t, bool modo);

// PRE: {c1 y c2 están inicializadas correctamente}
// POST: {Calcula y devuelve la distancia (en casillas) entre las dos posiciones dadas}
// Complejidad: O(1)
float getDistancia(Coordenada c1, Coordenada c2);

// PRE:{t está inicializada correctamente}
// POST: {Devuelve 'true' si el tablero está en una situación de fin de juego}
// Complejidad: 
bool isFin(Tab t);

// PRE:{t esta inicializada correctamente}
// POST: {Devuelve 'true' si la posicion indicada esta ocupada por una tarea y 'false' en caso contrario}
// Complejidad: O(n)
bool isTarea(Tab t, int fil, int col);

// PRE:{t esta inicializada correctamente}
// POST: {Devuelve 'true' en la posicion indicada esta ocupada por una caja y 'false' en caso contrario}
// Complejidad: O(n)
bool ocupado(Tab t, int fil, int col);

// PRE:{t esta inicializada correctamente}
// POST: {Devuelve 'true' en la posicion indicada esta ocupada por una meta y 'false' en caso contrario}
// Complejidad: O(n)
bool encontradoMetas(Tab t, int fil, int col);

// PRE: {d está inicializado correctamente}
// POST: {Devuelve en forma de string el valor de la dirección dada}
// Complejidad: O(1)
string direccionToString(Direccion d);

// PRE: {t está inicializado correctamente y las coordenadas de origen y destino están dentro de los límites válidos}
// POST: {Cambia las coordenadas de una caja del tablero}
// Complejidad: O(n)
void posicionarCaja(Tab &t, int x, int y, int tx, int ty);

void ejecutarTarea(Tab t, queue <Direccion> &sol);

void imprimirCola(queue<Direccion> &sol);


#endif /* TABLERO_H_ */
