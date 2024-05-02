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
	int nFiles = 0;

	for (int i = 0; i < figura.getTamany(); i++)
		for (int j = 0; j < figura.getTamany(); j++)
	{
		if (figura.getFigura(i, j) != 0)
		{
			tauler[i + figura.getPosicioX()][j + figura.getPosicioY()] = figura.getFigura(i, j);
		}
	}

	int ple = 0;

	for (int i = nFiles - 1; i >= 0; i--)
	{
		if (filaPlena(i))
		{
			eliminaFila(i);
			ple++;
		}
		else
			if (ple > 0)
			{
				baixaFila(i, ple);
			}
	}

	return ple;
}

bool Tauler::filaPlena(int fila)
{
	bool plena = true;

	for (int columna = 0; columna < MAX_COL; columna++)
	{
		if (tauler[fila][columna] == NO_COLOR)
		{
			plena = false;
		}
	}

	return plena;
}

void Tauler::eliminaFila(int fila)
{
	for (int columna = 0; columna < MAX_COL; columna++)
	{
		tauler[fila][columna] = NO_COLOR;
	}
}

void Tauler::baixaFila(int fila, int nFiles)
{
	for (int columna = 0; columna < MAX_COL; columna++)
	{
		tauler[fila + nFiles][columna] = tauler[fila][columna];
		tauler[fila][columna] = NO_COLOR;
	}

}


