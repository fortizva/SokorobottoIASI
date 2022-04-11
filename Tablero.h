#ifndef TABLERO_H_
#define TABLERO_H_

const int MAX=10;
typedef int TVectorTablero[MAX][MAX];

struct Tab {
	TVectorTablero vTablero;
	int ocupadas;
	int tam;
};

//PRE:{m inicializado correctamente,0<tam<MAX}
//POST:{inicia el tablero t a partir de los valores de la matriz m}
//Compejidad: O(n)²
void iniciarMatriz(Tab &t,int m[MAX][MAX], int tam);

//PRE:{valor>0,fila>=0,col>=0}
//POST:{inserta el valor de una nueva casilla en la posicion fila col}
//Compejidad: O(1)
void insertar(Tab &t, int valor,int fila, int col);

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

void actualizarTablero(Tab &t);

float calcularH(Tab &t);

#endif /* TABLERO_H_ */
