#include "Tauler.h"

Tauler::Tauler()
{
	for (int i = 0; i < MAX_FILA; i++)
		for (int j = 0; j < MAX_COL; j++)
		{
			tauler[i][j] = NO_COLOR;
		}
}

void Tauler::actualitzaTauler(Figura figura)
{
	for (int i = 0; i < figura.getTamany(); i++)
		for (int j = 0; j < figura.getTamany(); j++)
	{
		if (figura.getFigura(i, j) != 0)
		{
			tauler[i + figura.getPosicioX()][j + figura.getPosicioY()] = figura.getFigura(i, j)
		}
	}

	bool plena[MAX_ALCADA];

	for (int col = 0; col < MAX_COL; col++)
	{
		
	}
}

bool Tauler::filaPlena(int fila)
{
	bool plena = true;

	for (int columna = 0; columna < MAX_COL; columna++)
	{
		if (tauler.getTauler(fila, columna) == NO_COLOR)
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
		setTauler(0, fila, columna);
	}
}

void Tauler::baixaFila(int fila, int nFiles)
{
	for (int columna = 0; columna < MAX_COL; columna++)
	{
		setTauler(tauler[fila][columna], fila + nFiles, columna);
		setTauler(NO_FIGURA, fila, columna);
	}

}

int Tauler::borraFilaPlena()
{
	int ple = 0;
	for (int i = nFiles - 1; i >= 0; fila--)
	{
		if (filaPlena(i))
		{
			eliminaFila(fila);
			ple++;
		}
		else
			if (ple > 0)
			{
				baixafila(i, ple);
			}
	}
	return ple;
}
