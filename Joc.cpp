#include "Joc.h"

void Joc::inicialitza(const string& nomFitxer)
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

void Joc::escriuTauler(const string& nomFitxer)
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

bool Joc::giraFigura(DireccioGir direccio)
{

	ColorFigura m_aux[MAX_AMPLADA][MAX_ALCADA] = tauler.getTauler();
	ColorFigura m[MAX_AMPLADA][MAX_ALCADA];

	for(int i = 0; i < MAX_AMPLADA; i++)
        for(int j = 0; j < MAX_ALCADA; j++)
		{
            m[i][j] = m_aux[j][i];
        }

	switch (direccio)
	{
		case GIR_HORARI:
			
			break;

		case GIR_ANTI_HORARI:
			
			break;
	}

	

}

bool Joc::mouFigura(int dirX)
{

// Mirem si la figura te espai per a moure's cap als costats, si és vàlid movem el centre de la figura i si no, no

}

int Joc::baixaFigura()
{

// Mirem si al baixar la figura, les posicions que la rodejen estan ocupats.
// Si estan ocupats, la transformem en part del tauler i l'eliminem.

}