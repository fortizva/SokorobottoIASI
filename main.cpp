#include <iostream>
#include "boardParser.h"

using namespace std;

int main()
{
    boardParser parser("boards/SOKOBOTTO1.txt");

    for (int j = 0; j < parser.boardSize; j++)
    {
        for (int i = 0; i < parser.boardSize; i++)
        {
            cout << parser.board[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Programa finalizado" << endl;
}