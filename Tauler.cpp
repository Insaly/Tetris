#include "Tauler.h"

Tauler::Tauler()
{
	for (int i = 0; i < MAX_FILA; i++)
		for (int j = 0; j < MAX_COL; j++)
		{
			tauler[i][j] = NO_COLOR;
		}
}

void setTauler(ColorFigura color, int x, int y)
{
			tauler[x][y] = color;	
}


bool Tauler::casellaOcupada(ColorFigura tauler)
{
	bool Ocupada;
	if (tauler.getTauler() = NO_COLOR)
		Ocupada = true;
	else
		Ocupada = false;

	return Ocupada;
}

bool Tauler::filaPlena(int fila)
{
	for (int col = 0;col < MAX_COL;i++)
	{
		if (tauler.getTauler(fila, col) == NO_COLOR)
			return false;
	}
	return true;
}

void Tauler::eliminaFila(int fila)
{

	for (int col = 0; col < MAX_COL; col++)
	{
		setTauler(0,fila,col);
	}

}

void Tauler::baixaFila(int fila, int nFiles)
{
	for (int col = 0; col < MAX_COL; col++)
	{
		setTauler(tauler[fila][col], fila + nFiles, col);
		setTauler(0, fila, col);
	}

}

int Tauler::borraFilaPlena()
{
	int Ple = 0;
	for (int i = nfiles - 1;i >= 0; fila--)
	{
		if (filaPlena(i))
		{
			eliminaFila(fila);
			Ple++;
		}
		else
			if (ple > 0)
			{
				baixafila(i,Ple)
			}
	}
	return Ple;
}
