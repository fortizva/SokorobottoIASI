#include <iostream>
#include "boardParser.h"
#include "Tablero.h"

using namespace std;

int main()
{
    boardParser parser("boards/SOKOBOTTO1.txt");

    if (parser.lastParse())
    {
        /*for (int j = 0; j < parser.boardSize; j++)
        {
            for (int i = 0; i < parser.boardSize; i++)
            {
                cout << parser.board[i][j] << "\t";
            }
            cout << endl;
        }*/
        mostrarMatriz(parser.board);
    }
    cout << "Programa finalizado" << endl;
}