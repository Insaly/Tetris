#include "./Tauler.h"

Tauler::Tauler()
{
	for (int i = 0; i < N_FILES_TAULER; i++)
		for (int j = 0; j < N_COL_TAULER; j++)
		{
			tauler[i][j] = COLOR_NEGRE;
		}
}

int Tauler::actualitzaTauler(const Figura& figura)
{

	for (int i = 0; i < figura.getTamany(); i++)
		for (int j = 0; j < figura.getTamany(); j++)
	{
		if (figura.getFigura(i, j) != COLOR_NEGRE)
			tauler[i + figura.getPosicioY()][j + figura.getPosicioX()] = figura.getFigura(i, j);
	}

	int ple = 0, fila = 0;

	while (fila < N_FILES_TAULER)
	{
		if (filaPlena(fila))
		{
			eliminaFila(fila);
			ple++;
		}
		else
			fila++;
	}
	
	return ple;
}

bool Tauler::filaPlena(const int& fila)
{
	bool plena = true;
	int columna = 0;

	while (plena && columna < N_COL_TAULER)
	{
		if (tauler[fila][columna] == COLOR_NEGRE)
			plena = false;
		else
			columna++;
	}
	return plena;
}

void Tauler::eliminaFila(const int& fila)
{
	for (int index = fila; index > 0; index--)
		for (int columna = 0; columna < N_COL_TAULER; columna++)
	{
		tauler[index][columna] = tauler[index-1][columna];
	}

	for (int columna = 0; columna < N_COL_TAULER; columna++)
		tauler[0][columna] = COLOR_NEGRE;
}
