#include "Tauler.h"
Tauler::Tauler()
{
	for (int i = 0; i < MAX_FILA; i++)
		for (int j = 0; j < MAX_COL; j++)
		{
			tauler[i][j] = NO_COLOR;
		}
}

int Tauler::actualitzaTauler(Figura figura)
{

	for (int i = 0; i < figura.getTamany(); i++)
		for (int j = 0; j < figura.getTamany(); j++)
	{
		if (figura.getFigura(i, j) != COLOR_NEGRE)
		{
			tauler[i + figura.getPosicioY()][j + figura.getPosicioX()] = figura.getFigura(i, j);
		}
	}

	int ple = 0, fila = 0;

	while (fila < MAX_FILA)
	{
		if (filaPlena(fila))
		{
			eliminaFila(fila);
			ple++;
		}
		else
		{
			fila++;
		}
	}
	
	return ple;
}

bool Tauler::filaPlena(int fila)
{
	bool plena = true;
	int columna = 0;

	while (plena && columna < MAX_COL)
	{
		if (tauler[fila][columna] == COLOR_NEGRE)
		{
			plena = false;
		}
		else
		{
			columna++;
		}
	}
	return plena;
}

void Tauler::eliminaFila(int fila)
{
	for (int index = fila; index > 0; index--)
	{
		for (int columna = 0; columna < MAX_COL; columna++)
		{
			tauler[index][columna] = tauler[index-1][columna];
		}
	}

	for (int columna = 0; columna < MAX_COL; columna++)
	{
		tauler[0][columna] = COLOR_NEGRE;
	}
}

