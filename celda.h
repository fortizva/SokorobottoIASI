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

	celda(int x, int y, int vr, int vc, TipoCasilla t);

	void ponerX(int x);
	int obtenerX();

	void ponerY(int y);
	int obtenerY();

	void ponerValorR(int v);
	int obtenerValorR();
	void ponerValorC(int v);
	int obtenerValorC();

	void ponerTipo(TipoCasilla t);
	TipoCasilla obtenerTipo();

	virtual ~celda();

private:
	int cordX;
	int cordY;
	int valorR;
	int valorC;
	TipoCasilla tipo;
};

#endif /* CELDA_H_ */
