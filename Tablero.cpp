#include "Tablero.h"
#include "celda.h"
#include <iostream>
#include <cmath>
using namespace std;

void iniciarMatriz(Tab &t, celda m[MAX][MAX], int tam)
{
	int i;
	int j;
	t.tam = tam;
	for (i = 0; i < tam; i++)
	{
		for (j = 0; j < tam; j++)
		{
			t.vTablero[i][j].ponerTipo(m[i][j].obtenerTipo());
		}
	}
}

void insertar(Tab &t, celda::TipoCasilla valor, int fila, int col)
{
	t.vTablero[fila][col].ponerTipo(valor);
	t.ocupadas++;
}

void borrar(Tab &t, int fila, int col)
{
	t.vTablero[fila][col].ponerTipo(celda::AIRE);
	t.ocupadas--;
}

bool estaVacia(Tab t, int fila, int col)
{
	bool vacia;
	vacia = false;
	if (t.vTablero[fila][col].obtenerTipo()==celda::AIRE);
	{
		vacia = true;
	}
	return vacia;
}

int obtenerValorCasilla(Tab t, int fila, int col)
{
	return (t.vTablero[fila][col].obtenerTipo());
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
	// Aquí toca hacer el cálculo de h'. Probablemente estará relacionado con la distancia de los objetivos a la celda::CAJA más cercana.
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
			if (obtenerValorCasilla(t, fila, col) == celda::ROBOT)
			{
				// Si encontramos al celda::ROBOT salimos del bucle restando 1 a cada coordenada para anular los sumatorios del final de cada bucle.
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
			if (fila > 0 && obtenerValorCasilla(t, fila - 1, col) == celda::AIRE)
			{
				insertar(t, celda::ROBOT, fila - 1, col);
				insertar(t, celda::AIRE, fila, col);
				success = true;
			}
			break;
		case B:
			if (fila < t.tam - 1 && obtenerValorCasilla(t, fila + 1, col) == celda::AIRE)
			{
				insertar(t, celda::ROBOT, fila + 1, col);
				insertar(t, celda::AIRE, fila, col);
				success = true;
			}
			break;
		case I:
			if (col > 0 && obtenerValorCasilla(t, fila, col - 1) == celda::AIRE)
			{
				insertar(t, celda::ROBOT, fila, col - 1);
				insertar(t, celda::AIRE, fila, col);
				success = true;
			}
			break;
		case D:
			if (col < t.tam - 1 && obtenerValorCasilla(t, fila, col + 1) == celda::AIRE)
			{
				insertar(t, celda::ROBOT, fila, col + 1);
				insertar(t, celda::AIRE, fila, col);
				success = true;
			}
			break;
		case IA:
			if (fila > 0 && obtenerValorCasilla(t, fila - 1, col) == celda::CAJA)
			{
				insertar(t, celda::ROBOT, fila - 1, col);
				insertar(t, celda::CAJA, fila, col);
				success = true;
			}
			break;
		case IB:
			if (fila < t.tam - 1 && obtenerValorCasilla(t, fila + 1, col) == celda::CAJA)
			{
				insertar(t, celda::ROBOT, fila + 1, col);
				insertar(t, celda::CAJA, fila, col);
				success = true;
			}
			break;
		case II:
			if (col > 0 && obtenerValorCasilla(t, fila, col - 1) == celda::CAJA)
			{
				insertar(t, celda::ROBOT, fila, col - 1);
				insertar(t, celda::CAJA, fila, col);
				success = true;
			}
			break;
		case ID:
			if (col < t.tam - 1 && obtenerValorCasilla(t, fila, col + 1) == celda::CAJA)
			{
				insertar(t, celda::ROBOT, fila, col + 1);
				insertar(t, celda::CAJA, fila, col);
				success = true;
			}
			break;
		case EA:
			if (fila > 1 && obtenerValorCasilla(t, fila - 1, col) == celda::CAJA && obtenerValorCasilla(t, fila - 2, col) == celda::AIRE)
			{
				insertar(t, celda::CAJA, fila - 2, col);
				insertar(t, celda::ROBOT, fila - 1, col);
				insertar(t, celda::AIRE, fila, col);
				success = true;
			}
			break;
		case EB:
			if (fila < t.tam - 2 && obtenerValorCasilla(t, fila + 1, col) == celda::CAJA && obtenerValorCasilla(t, fila + 2, col) == celda::AIRE)
			{
				insertar(t, celda::CAJA, fila + 2, col);
				insertar(t, celda::ROBOT, fila + 1, col);
				insertar(t, celda::AIRE, fila, col);
				success = true;
			}
			break;
		case EI:
			if (col > 1 && obtenerValorCasilla(t, fila, col - 1) == celda::CAJA && obtenerValorCasilla(t, fila, col - 2) == celda::AIRE)
			{
				insertar(t, celda::CAJA, fila, col - 2);
				insertar(t, celda::ROBOT, fila, col - 1);
				insertar(t, celda::AIRE, fila, col);
				success = true;
			}
			break;
		case ED:
			if (col < t.tam - 2 && obtenerValorCasilla(t, fila, col + 1) == celda::CAJA && obtenerValorCasilla(t, fila, col + 2) == celda::AIRE)
			{
				insertar(t, celda::CAJA, fila, col + 2);
				insertar(t, celda::ROBOT, fila, col + 1);
				insertar(t, celda::AIRE, fila, col);
				success = true;
			}
			break;
		}
	}
	return success;
}
