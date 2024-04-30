#include "Joc.h"

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;

	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		TipusFigura tTipus;
		ColorFigura tColor;
		int x, y, rotacio, n = 0;

		fitxer >> tTipus >> x >> y >> rotacio;

		switch (tTipus)
		{
			case FIGURA_O:
				tColor = COLOR_GROC;
			case FIGURA_I:
				tColor = COLOR_BLAUCEL;
			case FIGURA_T:
				tColor = COLOR_MAGENTA;
			case FIGURA_L:
				tColor = COLOR_TARONJA;
			case FIGURA_J:
				tColor = COLOR_BLAUFOSC;
			case FIGURA_Z:
				tColor = COLOR_VERMELL;
			case FIGURA_S:
				tColor = COLOR_VERD;
		}

		m_figura(tColor, tTipus);
		m_figura.setPosicioX(x);
		m_figura.setPosicioY(y);

		for (int i = 0; i < rotacio; i++)
		{
			m_figura.giraFigura(GIR_HORARI);
		}

		while (!fitxer.eof())
		{
			fitxer >> m_tauler[0][n] >> m_tauler[1][n] >> m_tauler[2][n] >> m_tauler[3][n] >> m_tauler[4][n] >> m_tauler[5][n] >> m_tauler[6][n] >> m_tauler[7][n];
			n++;
		}
	}

	fitxer.close();
}

void Joc::escriuTauler(const string& nomFitxer)
{
	ofstream fitxer;
	int i = 0;

	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		while (i < MAX_FILA)
		{
			fitxer << m_tauler[0][i] << m_tauler[1][i] << m_tauler[2][i] << m_tauler[3][i] << m_tauler[4][i] << m_tauler[5][i] << m_tauler[6][i] << m_tauler[7][i];
			i++;
		}
	}

	fitxer.close();
}

bool Joc::giraFigura(DireccioGir direccio)
{
	bool moviment_valid = true;
	m_figura.giraFigura(direccio);

	for (int i = 0; i < m_figura.getTamany(); i++)
		for (int j = 0; i < m_figura.getTamany(); j++)
		{
			if (m_figura.getFigura(i, j) * m_tauler.getTauler(i, j) != 0)
			{
				moviment_valid = false;
			}
		}
	
	if (!moviment_valid)
	{
		switch (direccio)
		{
			case GIR_HORARI:
				m_figura.giraFigura(GIR_ANTI_HORARI); break;
			case GIR_ANTI_HORARI:
				m_figura.giraFigura(GIR_HORARI); break;
		}
	}
	
	return moviment_valid;
}

bool Joc::mouFigura(int dirX)
{
	bool moviment_valid = false;
	int posicio = m_figura.getPosicioX() + dirX;

	if (posicio + 1 > MAX_COL && posicio - 1 < 0)
	{
		for (int i = 0; i < m_figura.getTamany(); i++)
			for (int j = 0; j < m_figura.getTamany(); j++)
			{
				if (m_figura.getFigura(i, j) != NO_COLOR && m_tauler.getTauler())
			}
	}
	return moviment_valid;
}

int Joc::baixaFigura()
{

// Mirem si al baixar la figura, les posicions que la rodejen estan ocupats.
// Si estan ocupats, la transformem en part del tauler i l'eliminem.

}