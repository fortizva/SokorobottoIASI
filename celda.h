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


	celda(int x, int y, float vr, float vc, TipoCasilla t);

	void ponerX(int x);
	int obtenerX();

	void ponerY(int y);
	int obtenerY();

	void ponerValorR(float v);
	float obtenerValorR();

	void ponerValorC(float v);
	float obtenerValorC();

	void ponerTipo(TipoCasilla t);
	TipoCasilla obtenerTipo();

	virtual ~celda();

private:
	int cordX;
	int cordY;

	float valorR;
	float valorC;

	TipoCasilla tipo;
};

#endif /* CELDA_H_ */
