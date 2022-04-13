/*
 * celda.h
 *
 *  Created on: 13 abr 2022
 *      Author: ernes
 */

#ifndef CELDA_H_
#define CELDA_H_

class celda
{
public:
	enum TipoCasilla
	{
		AIRE,
		MURO,
		CAJA,
		META,
		ROBOT
	};

	celda();

	celda(int x, int y, int v, TipoCasilla t);

	void ponerX(int x);
	int obtenerX();

	void ponerY(int y);
	int obtenerY();

	void ponerValor(int v);
	int obtenerValor();

	void ponerTipo(TipoCasilla t);
	TipoCasilla obtenerTipo();

	virtual ~celda();
private:
	int cordX;
	int cordY;
	int valorH;
	TipoCasilla tipo;


};



#endif /* CELDA_H_ */
