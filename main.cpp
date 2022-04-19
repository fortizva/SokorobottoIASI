#include <iostream>
#include "boardParser.h"
#include "Tablero.h"
#include "eSimple.h"
#include "mPendiente.h"

using namespace std;

int main()
{
    Tab t; 
    celda m[MAX][MAX]; 
    int tam;
    Nodo nodo; 
    queue<Direccion> sol;
    boardParser parser("boards/SOKOBOTTO1.txt");
    int i;
    if (parser.lastParse())
    {
        iniciarMatriz(t, m, tam);
        mostrarMatriz(parser.board);
        cout << "Elija el modelo con el que quiere realizar el calculo" << endl;
        cout << "[1] Para escalada simple" << endl;
        cout << "[2] Para máxima pendiente" << endl;
        cin >> i;
        switch(i){
        case 1:
        escaladaSimple(nodo, &sol);
        cout << "Se ha realizado el cálculo mediante el metodo escalada simple"<<endl;
        break;

        case 2:
        maximaPendiente(nodo, &sol);
        cout << "Se ha realizado el cálculo mediante el metodo maxima pendiente"<<endl;
        break;

        default:
        break;
        
        }
    } else
        cout << "Hubo un problema al leer el fichero de tablero y el programa se detuvo." << endl;
    cout << "Programa finalizado" << endl;
}