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
    }
    cout << "Programa finalizado" << endl;
}