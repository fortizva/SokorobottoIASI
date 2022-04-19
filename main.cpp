#include <iostream>
#include "boardParser.h"
#include "Tablero.h"
#include "eSimple.h"
#include "mPendiente.h"


using namespace std;

void generarHijos (Nodo &n){
	int fila = n.t.robotCoord.y;
	int col = n.t.robotCoord.x;
		//Caso A
			if (fila > 0 && obtenerValorCasilla(n.t, fila - 1, col) == celda::AIRE && !ocupado(n.t, fila-1, col))
			{
				Nodo aux (n.t, n.t.vTablero[fila-1][col].obtenerValorR(), n.A ,TABLERO_H_::Direccion::A);
			}

		//Caso B
			if (fila < n.t.tam - 1 && obtenerValorCasilla(n.t, fila + 1, col) == celda::AIRE && !ocupado(n.t, fila+1, col))
			{
				Nodo aux (n.t, n.t.vTablero[fila+1][col].obtenerValorR(), n.A ,TABLERO_H_::Direccion::B);
			}

		//Caso I
			if (col > 0 && obtenerValorCasilla(n.t, fila, col - 1) == celda::AIRE && !ocupado(n.t, fila, col-1))
			{
				Nodo aux (n.t, n.t.vTablero[fila][col-1].obtenerValorR(), n.A ,TABLERO_H_::Direccion::I);
			}

		//Caso D
			if (col < n.t.tam - 1 && obtenerValorCasilla(n.t, fila, col + 1) == celda::AIRE && !ocupado(n.t, fila, col+1))
			{
				Nodo aux (n.t, n.t.vTablero[fila][col+1].obtenerValorR(), n.A ,TABLERO_H_::Direccion::D);
			}

		//Caso IA			//Ya que tenemos que saber que en esa posicion esta la caja
			if (fila > 0 && ocupado(n.t, fila-1, col) )
			{
				Nodo aux (n.t, n.t.vTablero[fila-1][col].obtenerValorR(), n.A ,TABLERO_H_::Direccion::IA);
			}
		//Caso IB
			if (fila < n.t.tam - 1 && ocupado(n.t, fila+1, col))
			{
				Nodo aux (n.t, n.t.vTablero[fila+1][col].obtenerValorR(), n.A ,TABLERO_H_::Direccion::IB);
			}
		//Caso II
			if (col > 0 && ocupado(n.t, fila, col-1))
			{
				Nodo aux (n.t, n.t.vTablero[fila][col-1].obtenerValorR(), n.A ,TABLERO_H_::Direccion::II);
			}
		//Caso ID
			if (col < n.t.tam - 1 && ocupado(n.t, fila, col+1))
			{
				Nodo aux (n.t, n.t.vTablero[fila][col+1].obtenerValorR(), n.A ,TABLERO_H_::Direccion::ID);
			}
		//Caso EA
			if (fila > 1 && ocupado(n.t, fila-1, col) && obtenerValorCasilla(n.t, fila - 2, col) == celda::AIRE)
			{
				Nodo aux (n.t, n.t.vTablero[fila-1][col].obtenerValorR(), n.A ,TABLERO_H_::Direccion::EA);
			}

		//Caso EB
			if (fila < n.t.tam - 2 && ocupado(n.t, fila+1, col) && obtenerValorCasilla(n.t, fila + 2, col) == celda::AIRE)
			{
				Nodo aux (n.t, n.t.vTablero[fila+1][col].obtenerValorR(), n.A ,TABLERO_H_::Direccion::EB);
			}

		//Caso EI
			if (col > 1 && ocupado(n.t, fila, col-1) && obtenerValorCasilla(n.t, fila, col - 2) == celda::AIRE)
			{
				Nodo aux (n.t, n.t.vTablero[fila][col-1].obtenerValorR(), n.A ,TABLERO_H_::Direccion::EI);
			}
		//Caso ED
			if (col < n.t.tam - 2 && ocupado(n.t, fila, col+1) && obtenerValorCasilla(n.t, fila, col + 2) == celda::AIRE)
			{
				Nodo aux (n.t, n.t.vTablero[fila][col+1].obtenerValorR(), n.A ,TABLERO_H_::Direccion::ED);
			}


}


int main()
{
    boardParser parser("boards/SOKOBOTTO1.txt");

    if (parser.lastParse())
    {
        mostrarMatriz(parser.board);

    }
    else{
        cout << "Hubo un problema al leer el fichero de tablero y el programa se detuvo." << endl;
    cout << "Programa finalizado" << endl;
}
}
