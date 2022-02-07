#include "boardParser.h"
#include <iostream>
#include <sstream>
#include <fstream>

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
        while (getline(file, data, ',') && i + j * boardSize < boardSize * boardSize)
        {
            this->board[i][j] = stoi(data);

            i++;
            if (i == boardSize)
            {
                i = 0;
                j++;
            }
        }
        file.close();
        this->parseSuccess = true;
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