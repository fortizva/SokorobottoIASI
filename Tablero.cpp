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
	t.vTablero[fila][col] = AIRE;
	t.ocupadas--;
}

bool estaVacia(Tab t, int fila, int col)
{
	bool vacia;
	vacia = false;
	if (t.vTablero[fila][col] == AIRE)
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
	// Aquí toca hacer el cálculo de h'. Probablemente estará relacionado con la distancia de los objetivos a la caja más cercana.
	return 0;
}

bool moverRobot(Tab &t, Direccion dir)
{
	bool success = false;
	int col = 0, fila = 0;
	while (fila < t.tam && !success)
	{
		while (col < t.tam && !success)
		{
			if (obtenerValorCasilla(t, fila, col) == ROBOT)
			{
				// Si encontramos al robot salimos del bucle restando 1 a cada coordenada para anular los sumatorios del final de cada bucle.
				fila--;
				col--;
				success = true;
			}
			col++;
		}
		fila++;
	}
	if (success)
	{
		success = false;
		switch (dir)
		{
		case A:
			if (fila > 0 && obtenerValorCasilla(t, fila - 1, col) == AIRE)
			{
				insertar(t, fila - 1, col, ROBOT);
				insertar(t, fila, col, AIRE);
				success = true;
			}
			break;
		case B:
			if (fila < t.tam - 1 && obtenerValorCasilla(t, fila + 1, col) == AIRE)
			{
				insertar(t, fila + 1, col, ROBOT);
				insertar(t, fila, col, AIRE);
				success = true;
			}
			break;
		case I:
			if (col > 0 && obtenerValorCasilla(t, fila, col - 1) == AIRE)
			{
				insertar(t, fila, col - 1, ROBOT);
				insertar(t, fila, col, AIRE);
				success = true;
			}
			break;
		case D:
			if (col < t.tam - 1 && obtenerValorCasilla(t, fila, col + 1) == AIRE)
			{
				insertar(t, fila, col + 1, ROBOT);
				insertar(t, fila, col, AIRE);
				success = true;
			}
			break;
		case IA:
			if (fila > 0 && obtenerValorCasilla(t, fila - 1, col) == CAJA)
			{
				insertar(t, fila - 1, col, ROBOT);
				insertar(t, fila, col, CAJA);
				success = true;
			}
			break;
		case IB:
			if (fila < t.tam - 1 && obtenerValorCasilla(t, fila + 1, col) == CAJA)
			{
				insertar(t, fila + 1, col, ROBOT);
				insertar(t, fila, col, CAJA);
				success = true;
			}
			break;
		case II:
			if (col > 0 && obtenerValorCasilla(t, fila, col - 1) == CAJA)
			{
				insertar(t, fila, col - 1, ROBOT);
				insertar(t, fila, col, CAJA);
				success = true;
			}
			break;
		case ID:
			if (col < t.tam - 1 && obtenerValorCasilla(t, fila, col + 1) == CAJA)
			{
				insertar(t, fila, col + 1, ROBOT);
				insertar(t, fila, col, CAJA);
				success = true;
			}
			break;
		case EA:
			if (fila > 1 && obtenerValorCasilla(t, fila - 1, col) == CAJA && obtenerValorCasilla(t, fila - 2, col) == AIRE)
			{
				insertar(t, fila - 2, col, CAJA);
				insertar(t, fila - 1, col, ROBOT);
				insertar(t, fila, col, AIRE);
				success = true;
			}
			break;
		case EB:
			if (fila < t.tam - 2 && obtenerValorCasilla(t, fila + 1, col) == CAJA && obtenerValorCasilla(t, fila + 2, col) == AIRE)
			{
				insertar(t, fila + 2, col, CAJA);
				insertar(t, fila + 1, col, ROBOT);
				insertar(t, fila, col, AIRE);
				success = true;
			}
			break;
		case EI:
			if (col > 1 && obtenerValorCasilla(t, fila, col - 1) == CAJA && obtenerValorCasilla(t, fila, col - 2) == AIRE)
			{
				insertar(t, fila, col - 2, CAJA);
				insertar(t, fila, col - 1, ROBOT);
				insertar(t, fila, col, AIRE);
				success = true;
			}
			break;
		case ED:
			if (col < t.tam - 2 && obtenerValorCasilla(t, fila, col + 1) == CAJA && obtenerValorCasilla(t, fila, col + 2) == AIRE)
			{
				insertar(t, fila, col + 2, CAJA);
				insertar(t, fila, col + 1, ROBOT);
				insertar(t, fila, col, AIRE);
				success = true;
			}
			break;
		}
	}
	return success;
}