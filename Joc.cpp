#include "Joc.h"

void incialitza(const string& nomFitxer)
{
	ColorFigura mat[MAX_FILA][MAX_COL];
	ifstream fitxer;
	int i = 0;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		while (!fitxer.eof())
		{
			fitxer >> mat[0][i] >> mat[1][i] >> mat[2][i] >> mat[3][i] >> mat[4][i] >> mat[5][i] >> mat[6][i] >> mat[7][i];
			i++;
		}
	}
	fitxer.close();
	tauler.setTauler(mat);
}


void escriuTauler(const string& nomFitxer)
{
	ColorFigura mat[MAX_FILA][MAX_COL] = tauler.getTauler();
	ofstream fitxer;
	int i = 0;

	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		while (i < MAX_FILA)
		{
			fitxer << mat[0][i] << mat[1][i] << mat[2][i] << mat[3][i] << mat[4][i] << mat[5][i] << mat[6][i] << mat[7][i];
			i++;
		}
	}
	fitxer.close();
	

}

bool giraFigura(DireccioGir direccio)
{


}

bool mouFigura(int dirX)
{



}

int baixaFigura()
{



}