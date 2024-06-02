#ifndef TAULER_H
#define TAULER_H

#include "./InfoJoc.h"
#include "./Figura.h"

class Tauler
{
public:
	Tauler();
	void setTauler(const ColorFigura& color, const int& x, const int& y) { tauler[x][y] = color; }
	ColorFigura getTauler(const int& x, const int& y) const { return tauler[x][y]; }
	int actualitzaTauler(const Figura& figura);
private:
	bool filaPlena(const int& fila);
	void eliminaFila(const int& fila);
	ColorFigura tauler[N_FILES_TAULER][N_COL_TAULER];
};
#endif