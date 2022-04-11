#include "Tablero.h"
#include <iostream>
#include <cmath>
using namespace std;

void iniciarMatriz(Tab &t, int m[MAX][MAX], int tam)
{
	int i;
	int j;
	t.tam = tam;
	for (i = 0; i < tam; i++)
	{
		for (j = 0; j < tam; j++)
		{
			t.vTablero[i][j] = m[i][j];
		}
	}
}

void insertar(Tab &t, int valor, int fila, int col)
{
	t.vTablero[fila][col] = valor;
	t.ocupadas++;
}

void borrar(Tab &t, int fila, int col)
{
	t.vTablero[fila][col]=0;
	t.ocupadas--;
}

bool estaVacia(Tab t, int fila, int col)
{
	bool vacia;
	vacia = false;
	if (t.vTablero[fila][col] == 0)
	{
		vacia = true;
	}
	return vacia;
}

int obtenerValorCasilla(Tab t, int fila, int col)
{
	return (t.vTablero[fila][col]);
}

void mostrarMatriz(Tab t)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << obtenerValorCasilla(t, i, j) << " ";
		}
		cout << endl;
	}
}

float calcularH(Tab &t)
{

	return 0;
}
