#include <iostream>
#include "boardParser.h"
#include "Tablero.h"
#include "eSimple.h"
#include "mPendiente.h"
#include "Nodo.h"

using namespace std;

/*
	Cada caja decide la posición más ventajosa y crea un nodo cuyo tablero tiene establecidas las posiciones a las que
	debe ir el robot. Una vez el robot entre en una de esas posiciones ejecutará el movimiento en función de su posición
*/
void generarMovsCaja(Nodo &n, Coordenada coordCaja)
{
	int fila = coordCaja.y;
	int col = coordCaja.x;
	// Caso A
	if (fila > 0 && obtenerValorCasilla(n.t, fila - 1, col) == celda::AIRE && !ocupado(n.t, fila - 1, col))
	{
		Nodo aux(n.t, n.t.vTablero[fila - 1][col].obtenerValorC(), &n, TABLERO_H_::Direccion::A);
		// Insertamos la posición deseada para intercambiar con la caja
		Tarea task;
		Coordenada pos;
		pos.x = col;
		pos.y = fila - 1;
		task.coord = pos;
		task.task = Direccion::IB;
		aux.t.posiciones.push_back(task);
		// Insertamos la posición contraria para empujar la caja
		if (obtenerValorCasilla(n.t, fila + 1, col) == celda::AIRE)
		{
			pos.y = fila + 1;
			task.coord = pos;
			task.task = Direccion::EA;
			aux.t.posiciones.push_back(task);
		}
		TABLERO_H_::calcularH(aux.t, true);
		n.setHijo(aux);
	}

	// Caso B
	if (fila < n.t.tam - 1 && obtenerValorCasilla(n.t, fila + 1, col) == celda::AIRE && !ocupado(n.t, fila + 1, col))
	{
		Nodo aux(n.t, n.t.vTablero[fila + 1][col].obtenerValorC(), &n, TABLERO_H_::Direccion::B);
		// Insertamos la posición deseada para intercambiar con la caja
		Tarea task;
		Coordenada pos;
		pos.x = col;
		pos.y = fila + 1;
		task.coord = pos;
		task.task = Direccion::IA;
		aux.t.posiciones.push_back(task);
		// Insertamos la posición contraria para empujar la caja
		if (obtenerValorCasilla(n.t, fila - 1, col) == celda::AIRE)
		{
			pos.y = fila - 1;
			task.coord = pos;
			task.task = Direccion::EB;
			aux.t.posiciones.push_back(task);
		}
		TABLERO_H_::calcularH(aux.t, true);
		n.setHijo(aux);
	}

	// Caso I
	if (col > 0 && obtenerValorCasilla(n.t, fila, col - 1) == celda::AIRE && !ocupado(n.t, fila, col - 1))
	{
		Nodo aux(n.t, n.t.vTablero[fila][col - 1].obtenerValorC(), &n, TABLERO_H_::Direccion::I);
		// Insertamos la posición deseada para intercambiar con la caja
		Tarea task;
		Coordenada pos;
		pos.x = col - 1;
		pos.y = fila;
		task.coord = pos;
		task.task = Direccion::ID;
		aux.t.posiciones.push_back(task);
		// Insertamos la posición contraria para empujar la caja
		if (obtenerValorCasilla(n.t, fila, col + 1) == celda::AIRE)
		{
			pos.y = col + 1;
			task.coord = pos;
			task.task = Direccion::EI;
			aux.t.posiciones.push_back(task);
		}
		TABLERO_H_::calcularH(aux.t, true);
		n.setHijo(aux);
	}

	// Caso D
	if (col < n.t.tam - 1 && obtenerValorCasilla(n.t, fila, col + 1) == celda::AIRE && !ocupado(n.t, fila, col + 1))
	{
		Nodo aux(n.t, n.t.vTablero[fila][col + 1].obtenerValorC(), &n, TABLERO_H_::Direccion::D);
		// Insertamos la posición deseada para intercambiar con la caja
		Tarea task;
		Coordenada pos;
		pos.x = col + 1;
		pos.y = fila;
		task.coord = pos;
		task.task = Direccion::II;
		aux.t.posiciones.push_back(task);
		// Insertamos la posición contraria para empujar la caja
		if (obtenerValorCasilla(n.t, fila, col - 1) == celda::AIRE)
		{
			pos.y = col - 1;
			task.coord = pos;
			task.task = Direccion::ED;
			aux.t.posiciones.push_back(task);
		}
		TABLERO_H_::calcularH(aux.t, true);
		n.setHijo(aux);
	}
}



int main()
{
	queue<Direccion> sol;
	boardParser parser("src/boards/SOKOBOTTO4.txt");
	// Usamos dos nodos para no mezclar los hijos de ambas heurísticas
	Nodo nodoC(parser.board, 9999, NULL, Direccion::A);
	Nodo nodoR(parser.board, 9999, NULL, Direccion::A);
	int i;
	if (parser.lastParse())
	{
		mostrarMatriz(parser.board);
		cout << "Elija el modelo con el que quiere realizar el calculo" << endl;
		cout << "[1] Para escalada simple" << endl;
		cout << "[2] Para máxima pendiente" << endl;
		i = 1;
		//cin >> i;

		switch (i)
		{
		case 1:
			//while(!TABLERO_H_::isFin(nodoC.t)) { // No añado el while aún porque falta implementar el método que compruebe el final
			//  Generamos las posiciones a las que se podría mover el robot para interactuar con las cajas
			for (Coordenada c : nodoC.t.cajas)
			{
				generarMovsCaja(nodoC, c); // Tocará modificar este método para que con heurística sólo elija la mejor casilla (con sus consiguientes 2 tareas de intercambiar y empujar)
			}

			// Copiamos las posiciones deseadas (previamente filtradas con heurística) de todas las cajas al nodo del robot
			nodoR.t.posiciones = nodoC.t.posiciones;

			// Calculamos la ruta del robot a las posiciones
			TABLERO_H_::calcularH(nodoR.t, false);

			for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						cout << nodoR.t.vTablero[i][j].obtenerValorR() << " ";
					}
					cout << endl;
				}

			// Genera hijos
			nodoR.generarHijos();

			// Llevamos el robot a una tarea
			ESIMPLE_H_::eSimpleRobot(nodoR, sol);

			TABLERO_H_::imprimirCola(sol);

			if (TABLERO_H_::isTarea(nodoR.t, nodoR.t.robotCoord.y, nodoR.t.robotCoord.x))
			{
				// TODO: Hacer algo aquí para ejecutar la tarea de la coordenada en la que se encuentra el robot
				TABLERO_H_::ejecutarTarea(nodoR.t, sol);
			}
			// Actualizar el nodoC para que se encuentre en la situación del nodoR
			nodoC.t.posiciones = nodoR.t.posiciones;

			// } // FIN DEL WHILE
			cout << "Se ha realizado el cálculo mediante el metodo escalada simple" << endl;
			break;

		case 2:
			while(!TABLERO_H_::isFin(nodoC.t)) {
			for (Coordenada c : nodoC.t.cajas)
			{
				generarMovsCaja(nodoC, c); // Tocará modificar este método para que con heurística sólo elija la mejor casilla (con sus consiguientes 2 tareas de intercambiar y empujar)
			}

			// Copiamos las posiciones deseadas (previamente filtradas con heurística) de todas las cajas al nodo del robot
			nodoR.t.posiciones = nodoC.t.posiciones;

			// Calculamos la ruta del robot a las posiciones
			TABLERO_H_::calcularH(nodoR.t, false);

			// Llevamos el robot a una tarea
			MPENDIENTE_H_::maximaPendiente(nodoC, sol);

			if (TABLERO_H_::isTarea(nodoR.t, nodoR.t.robotCoord.y, nodoR.t.robotCoord.x))
			{
				// TODO: Hacer algo aquí para ejecutar la tarea de la coordenada en la que se encuentra el robot
				// TABLERO_H_::ejecutarTarea(nodoR.t, sol)

			}
			// Actualizar el nodoC para que se encuentre en la situación del nodoR
			nodoC.t.posiciones = nodoR.t.posiciones;

			 } // FIN DEL WHILE
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
