#include "boardParser.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "celda.h"

#define DEFAULT_BOARD "boards/SOKOBOTTO1.txt"

using namespace std;

boardParser::boardParser()
{
    parseBoard(DEFAULT_BOARD);
}

boardParser::boardParser(string path)
{
    parseBoard(path);
}

bool boardParser::parseBoard(string path)
{
    ifstream file(path);
    char value;

    if (file.is_open())
    {
        string data = "";
        int i = 0, j = 0;
        bool failedParse = false;
        Coordenada aux;
        while (getline(file, data, ',') && j * boardSize + i < boardSize * boardSize && !failedParse)
        {
            switch ((celda::TipoCasilla)stoi(data))
            {
            case celda::TipoCasilla::AIRE:
            case celda::TipoCasilla::MURO:
                insertar(this->board, (celda::TipoCasilla)stoi(data), j, i);
                break;
            case celda::TipoCasilla::CAJA:
                insertar(this->board, celda::TipoCasilla::AIRE, j, i);
                aux.x = i;
                aux.y = j;
                this->board.cajas.push_back(aux);
                break;
            case celda::TipoCasilla::META:
                insertar(this->board, celda::TipoCasilla::AIRE, j, i);
                aux.x = i;
                aux.y = j;
                this->board.metas.push_back(aux);
                break;
            case celda::TipoCasilla::ROBOT:
                insertar(this->board, celda::TipoCasilla::AIRE, j, i);
                this->board.robotCoord.x = i;
                this->board.robotCoord.y = j;
                break;
            default:
                failedParse = true;
                break;
            }
            i++;
            if (i == boardSize)
            {
                i = 0;
                j++;
            }
        }
        file.close();
        this->parseSuccess = !failedParse;
    }
    else
    {
        cout << "Error al intentar analizar el fichero \"" << path << "\"" << endl;
        this->parseSuccess = false;
    }
    return parseSuccess;
}

bool boardParser::lastParse()
{
    return parseSuccess;
}
