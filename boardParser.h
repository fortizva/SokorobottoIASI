#ifndef BOARD_PARSER_H_
#define BOARD_PARSER_H_

#include <iostream>
#include <fstream>

using namespace std;

/**
 * @brief Clase encargada de obtener y mantener los datos del tablero
 * 
 */
class boardParser
{
public:
    /**
     * @brief Tamaño del tablero
     * 
     */
    static const int boardSize = 10;

    /**
     * @brief Tablero de juego
     * 
     */
    int board[boardSize][boardSize];

    /**
     * @brief Constructor por defecto de boardParser.
     * 
     */
    boardParser();

    /**
     * @brief Constructor de boardParser, emplea la ruta introducida.
     * 
     * @param path Ruta del tablero
     */
    boardParser(string path);

    /**
     * @brief Ordena a analizar el tablero desde el fichero indicado.
     * 
     * @param path Ruta del tablero
     */
    bool parseBoard(string path);
};

#endif /* BOARD_PARSER_H_ */