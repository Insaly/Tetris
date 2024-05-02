#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
public:
	Tauler();
	void setTauler(ColorFigura color, int x, int y) { tauler[x][y] = color; }
	ColorFigura getTauler(int x, int y) const { return tauler[x][y]; }
	int actualitzaTauler(Figura figura);
	bool filaPlena(int fila);
	void baixaFila(int fila,int nFiles);
	void eliminaFila(int fila);

private:
	ColorFigura tauler[MAX_FILA][MAX_COL];
};
#endif