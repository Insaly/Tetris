#ifndef TAULER_H
#define TAULER_H

#include "./InfoJoc.h"
#include "./Figura.h"

class Tauler
{
public:
	Tauler();
	void setTauler(ColorFigura color, int x, int y) { tauler[x][y] = color; }
	ColorFigura getTauler(int x, int y) const { return tauler[x][y]; }
	int actualitzaTauler(Figura figura);
private:
	bool filaPlena(int fila);
	void eliminaFila(int fila);
	ColorFigura tauler[N_FILES_TAULER][N_COL_TAULER];
};
#endif