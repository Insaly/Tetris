#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
public:
	Tauler();
	
	void setTauler(ColorFigura n_tauler[MAX_FILA][MAX_COL]) { tauler = n_tauler; }
	ColorFigura getTauler() const { return tauler; }

private:
	ColorFigura tauler[MAX_FILA][MAX_COL];
	Figura figuraActual;

};
#endif