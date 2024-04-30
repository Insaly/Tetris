#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
public:
	Tauler();
	
	void setTauler(ColorFigura n_tauler[MAX_FILA][MAX_COL]);
	ColorFigura getTauler(int x, int y) const { return tauler[x][y]; }
	bool casellaOcupada(ColorFigura tauler);
	void eliminaFila(int fila);
	bool filaPlena(int fila);
	void baixaFila(int fila,int nFiles);
	int borraFilaPlena()
private:
	ColorFigura tauler[MAX_FILA][MAX_COL];
	Figura figuraActual;
	

};
#endif