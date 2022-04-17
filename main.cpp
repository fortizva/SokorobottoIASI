#include <iostream>
#include "boardParser.h"
#include "Tablero.h"

using namespace std;

int main()
{
    boardParser parser("boards/SOKOBOTTO1.txt");

    if (parser.lastParse())
    {
        mostrarMatriz(parser.board);
    } else
        cout << "Hubo un problema al leer el fichero de tablero y el programa se detuvo." << endl;
    cout << "Programa finalizado" << endl;
}