#include "Tablero.h"
#include "celda.h"
#include <cmath>
#include "Lista.h"
using namespace std;

void iniciarMatriz(Tab &t, celda m[MAX][MAX], int tam)
{
	int i;
	int j;
	t.tam = tam;
	for (i = 0; i < tam; i++)
	{
		for (j = 0; j < tam; j++)
		{
			t.vTablero[i][j].ponerTipo(m[i][j].obtenerTipo());
		}
	}
}

void insertar(Tab &t, celda::TipoCasilla valor, int fila, int col)
{
	t.vTablero[fila][col].ponerTipo(valor);
	t.ocupadas++;
}

void borrar(Tab &t, int fila, int col)
{
	t.vTablero[fila][col].ponerTipo(celda::AIRE);
	t.ocupadas--;
}

bool estaVacia(Tab t, int fila, int col)
{
	bool vacia;
	vacia = false;
	if (t.vTablero[fila][col].obtenerTipo() == celda::AIRE)
	{
		vacia = true;
	}
	return vacia;
}

int obtenerValorCasilla(Tab t, int fila, int col)
{
	return (t.vTablero[fila][col].obtenerTipo());
}

void mostrarMatriz(Tab t)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << obtenerValorCasilla(t, i, j) << " ";
		}
		cout << endl;
	}
}

void calcularH(Tab &t, bool modo)
{
	// Usar la lista de coordenadas correspondiente a cada modo
	vector<Coordenada> coords;
	if (modo)
	{
		for (int i = 0; i < t.posiciones.size(); i++)
		{
			coords.push_back(t.posiciones.at(i).coord);
		}
	}
	else
		coords = t.metas;
	Coordenada c;
	int minDist, dist, i;

	for (int fila = 0; fila < t.tam; fila++)
	{
		c.y = fila;
		for (int col = 0; col < t.tam; col++)
		{
			c.x = col;
			minDist = 9999;
			// Obtenemos las coordenadas de menor distancia para cada casilla
			for (i = 0; i < coords.size(); i++)
			{
				dist = getDistancia(c, coords[i]);
				if (dist < minDist)
					minDist = dist;
			}
			if (modo)
				t.vTablero[fila][col].ponerValorC(minDist);
			else
				t.vTablero[fila][col].ponerValorR(minDist);
		}
	}
}

float getDistancia(Coordenada c1, Coordenada c2)
{
	return sqrt(pow((c1.x - c2.x), 2) + pow((c1.y - c2.y), 2));
}

// TODO: Modificar este método para poder usarlo con el nuevo planteamiento (sin necesidad de modificar tablero).
/*
bool moverRobot(Tab &t, Direccion dir)
{
	bool success = false;
	int col = 0, fila = 0;
	while (fila < t.tam && !success)
	{
		while (col < t.tam && !success)
		{
			if (obtenerValorCasilla(t, fila, col) == celda::ROBOT)
			{
				// Si encontramos al celda::ROBOT salimos del bucle restando 1 a cada coordenada para anular los sumatorios del final de cada bucle.
				fila--;
				col--;
				success = true;
			}
			col++;
		}
		fila++;
	}
	if (success)
	{
		success = false;
		switch (dir)
		{
		case A:
			if (fila > 0 && obtenerValorCasilla(t, fila - 1, col) == celda::AIRE)
			{
				insertar(t, celda::ROBOT, fila - 1, col);
				insertar(t, celda::AIRE, fila, col);
				success = true;
			}
			break;
		case B:
			if (fila < t.tam - 1 && obtenerValorCasilla(t, fila + 1, col) == celda::AIRE)
			{
				insertar(t, celda::ROBOT, fila + 1, col);
				insertar(t, celda::AIRE, fila, col);
				success = true;
			}
			break;
		case I:
			if (col > 0 && obtenerValorCasilla(t, fila, col - 1) == celda::AIRE)
			{
				insertar(t, celda::ROBOT, fila, col - 1);
				insertar(t, celda::AIRE, fila, col);
				success = true;
			}
			break;
		case D:
			if (col < t.tam - 1 && obtenerValorCasilla(t, fila, col + 1) == celda::AIRE)
			{
				insertar(t, celda::ROBOT, fila, col + 1);
				insertar(t, celda::AIRE, fila, col);
				success = true;
			}
			break;
		case IA:
			if (fila > 0 && obtenerValorCasilla(t, fila - 1, col) == celda::CAJA)
			{
				insertar(t, celda::ROBOT, fila - 1, col);
				insertar(t, celda::CAJA, fila, col);
				success = true;
			}
			break;
		case IB:
			if (fila < t.tam - 1 && obtenerValorCasilla(t, fila + 1, col) == celda::CAJA)
			{
				insertar(t, celda::ROBOT, fila + 1, col);
				insertar(t, celda::CAJA, fila, col);
				success = true;
			}
			break;
		case II:
			if (col > 0 && obtenerValorCasilla(t, fila, col - 1) == celda::CAJA)
			{
				insertar(t, celda::ROBOT, fila, col - 1);
				insertar(t, celda::CAJA, fila, col);
				success = true;
			}
			break;
		case ID:
			if (col < t.tam - 1 && obtenerValorCasilla(t, fila, col + 1) == celda::CAJA)
			{
				insertar(t, celda::ROBOT, fila, col + 1);
				insertar(t, celda::CAJA, fila, col);
				success = true;
			}
			break;
		case EA:
			if (fila > 1 && obtenerValorCasilla(t, fila - 1, col) == celda::CAJA && obtenerValorCasilla(t, fila - 2, col) == celda::AIRE)
			{
				insertar(t, celda::CAJA, fila - 2, col);
				insertar(t, celda::ROBOT, fila - 1, col);
				insertar(t, celda::AIRE, fila, col);
				success = true;
			}
			break;
		case EB:
			if (fila < t.tam - 2 && obtenerValorCasilla(t, fila + 1, col) == celda::CAJA && obtenerValorCasilla(t, fila + 2, col) == celda::AIRE)
			{
				insertar(t, celda::CAJA, fila + 2, col);
				insertar(t, celda::ROBOT, fila + 1, col);
				insertar(t, celda::AIRE, fila, col);
				success = true;
			}
			break;
		case EI:
			if (col > 1 && obtenerValorCasilla(t, fila, col - 1) == celda::CAJA && obtenerValorCasilla(t, fila, col - 2) == celda::AIRE)
			{
				insertar(t, celda::CAJA, fila, col - 2);
				insertar(t, celda::ROBOT, fila, col - 1);
				insertar(t, celda::AIRE, fila, col);
				success = true;
			}
			break;
		case ED:
			if (col < t.tam - 2 && obtenerValorCasilla(t, fila, col + 1) == celda::CAJA && obtenerValorCasilla(t, fila, col + 2) == celda::AIRE)
			{
				insertar(t, celda::CAJA, fila, col + 2);
				insertar(t, celda::ROBOT, fila, col + 1);
				insertar(t, celda::AIRE, fila, col);
				success = true;
			}
			break;
		}
	}
	return success;
}
*/
bool isFin(Tab t)
{
	return false;
}

bool ocupado(Tab t, int fil, int col)
{
	int i = 0;
	bool enc = false;
	while (i < t.cajas.size() && !enc)
	{
		if (t.cajas[i].x == fil and t.cajas[i].y == col)
		{
			enc = true;
		}
		i++;
	}
	return enc;
}

bool encontradoMetas(Tab t, int fil, int col)
{
	int i = 0;
	bool enc = false;
	while (i < t.metas.size() && !enc)
	{
		if (t.metas[i].x == fil and t.metas[i].y == col)
		{
			enc = true;
		}
		i++;
	}
	return enc;
}

string direccionToString(Direccion d)
{
	string res;
	switch (d)
	{
	case Direccion::A:
		res = "A";
		break;
	case Direccion::B:
		res = "B";
		break;
	case Direccion::I:
		res = "I";
		break;
	case Direccion::D:
		res = "D";
		break;
	case Direccion::EA:
		res = "EA";
		break;
	case Direccion::EB:
		res = "EB";
		break;
	case Direccion::EI:
		res = "EI";
		break;
	case Direccion::ED:
		res = "ED";
		break;
	case Direccion::IA:
		res = "IA";
		break;
	case Direccion::IB:
		res = "IB";
		break;
	case Direccion::II:
		res = "II";
		break;
	case Direccion::ID:
		res = "ID";
		break;
	default:
		res = "";
		break;
	}
	return res;
}

void posicionarCaja(Tab &t, int x, int y, int tx, int ty)
{
	bool found = false;
	int i = 0;
	while (!found && i < t.cajas.size())
	{
		if (t.cajas.at(i).x == x && t.cajas.at(i).y == y)
		{
			t.cajas.at(i).x = tx;
			t.cajas.at(i).y = ty;
			found = true;
		}
		i++;
	}
}

bool isTarea(Tab t, int fil, int col){
	int i = 0;
	bool found = false;
	while(!found && i < t.posiciones.size()){
		if(t.posiciones.at(i).coord.x == col && t.posiciones.at(i).coord.y == fil)
			found = true;
		i++;
	}
	return found;
}