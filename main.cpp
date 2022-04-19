#include <iostream>
#include "boardParser.h"
#include "Tablero.h"
#include "eSimple.h"
#include "mPendiente.h"

using namespace std;

void generarHijos(Nodo &n)
{
	int fila = n.t.robotCoord.y;
	int col = n.t.robotCoord.x;
	// Caso A
	if (fila > 0 && obtenerValorCasilla(n.t, fila - 1, col) == celda::AIRE && !ocupado(n.t, fila - 1, col))
	{
		Nodo aux(n.t, n.t.vTablero[fila - 1][col].obtenerValorR(), &n, TABLERO_H_::Direccion::A);
		n.setHijo(aux);
	}

	// Caso B
	if (fila < n.t.tam - 1 && obtenerValorCasilla(n.t, fila + 1, col) == celda::AIRE && !ocupado(n.t, fila + 1, col))
	{
		Nodo aux(n.t, n.t.vTablero[fila + 1][col].obtenerValorR(), &n, TABLERO_H_::Direccion::B);
		n.setHijo(aux);
	}

	// Caso I
	if (col > 0 && obtenerValorCasilla(n.t, fila, col - 1) == celda::AIRE && !ocupado(n.t, fila, col - 1))
	{
		Nodo aux(n.t, n.t.vTablero[fila][col - 1].obtenerValorR(), &n, TABLERO_H_::Direccion::I);
		n.setHijo(aux);
	}

	// Caso D
	if (col < n.t.tam - 1 && obtenerValorCasilla(n.t, fila, col + 1) == celda::AIRE && !ocupado(n.t, fila, col + 1))
	{
		Nodo aux(n.t, n.t.vTablero[fila][col + 1].obtenerValorR(), &n, TABLERO_H_::Direccion::D);
		n.setHijo(aux);
	}

	// Caso IA			//Ya que tenemos que saber que en esa posicion esta la caja
	if (fila > 0 && ocupado(n.t, fila - 1, col))
	{
		Nodo aux(n.t, n.t.vTablero[fila - 1][col].obtenerValorR(), &n, TABLERO_H_::Direccion::IA);
		n.setHijo(aux);
	}
	// Caso IB
	if (fila < n.t.tam - 1 && ocupado(n.t, fila + 1, col))
	{
		Nodo aux(n.t, n.t.vTablero[fila + 1][col].obtenerValorR(), &n, TABLERO_H_::Direccion::IB);
		n.setHijo(aux);
	}
	// Caso II
	if (col > 0 && ocupado(n.t, fila, col - 1))
	{
		Nodo aux(n.t, n.t.vTablero[fila][col - 1].obtenerValorR(), &n, TABLERO_H_::Direccion::II);
		n.setHijo(aux);
	}
	// Caso ID
	if (col < n.t.tam - 1 && ocupado(n.t, fila, col + 1))
	{
		Nodo aux(n.t, n.t.vTablero[fila][col + 1].obtenerValorR(), &n, TABLERO_H_::Direccion::ID);
		n.setHijo(aux);
	}
	// Caso EA
	if (fila > 1 && ocupado(n.t, fila - 1, col) && obtenerValorCasilla(n.t, fila - 2, col) == celda::AIRE)
	{
		Nodo aux(n.t, n.t.vTablero[fila - 1][col].obtenerValorR(), &n, TABLERO_H_::Direccion::EA);
		n.setHijo(aux);
	}

	// Caso EB
	if (fila < n.t.tam - 2 && ocupado(n.t, fila + 1, col) && obtenerValorCasilla(n.t, fila + 2, col) == celda::AIRE)
	{
		Nodo aux(n.t, n.t.vTablero[fila + 1][col].obtenerValorR(), &n, TABLERO_H_::Direccion::EB);
		n.setHijo(aux);
	}

	// Caso EI
	if (col > 1 && ocupado(n.t, fila, col - 1) && obtenerValorCasilla(n.t, fila, col - 2) == celda::AIRE)
	{
		Nodo aux(n.t, n.t.vTablero[fila][col - 1].obtenerValorR(), &n, TABLERO_H_::Direccion::EI);
		n.setHijo(aux);
	}
	// Caso ED
	if (col < n.t.tam - 2 && ocupado(n.t, fila, col + 1) && obtenerValorCasilla(n.t, fila, col + 2) == celda::AIRE)
	{
		Nodo aux(n.t, n.t.vTablero[fila][col + 1].obtenerValorR(), &n, TABLERO_H_::Direccion::ED);
		n.setHijo(aux);
	}
}

int main()
{
	Nodo nodo;
	queue<Direccion> sol;
	boardParser parser("boards/SOKOBOTTO1.txt");
	int i;
	if (parser.lastParse())
	{
		mostrarMatriz(parser.board);
		cout << "Elija el modelo con el que quiere realizar el calculo" << endl;
		cout << "[1] Para escalada simple" << endl;
		cout << "[2] Para máxima pendiente" << endl;
		cin >> i;
		switch (i)
		{
		case 1:
			ESIMPLE_H_::escaladaSimple(nodo, sol);
			cout << "Se ha realizado el cálculo mediante el metodo escalada simple" << endl;
			break;

		case 2:
			MPENDIENTE_H_::maximaPendiente(nodo, sol);
			cout << "Se ha realizado el cálculo mediante el metodo maxima pendiente" << endl;
			break;

		default:
			break;
		}
		while (!sol.empty())
		{
			cout << TABLERO_H_::direccionToString(sol.front());
			sol.pop();
		}
	}
	else
		cout << "Hubo un problema al leer el fichero de tablero y el programa se detuvo." << endl;
	cout << "Programa finalizado" << endl;
}