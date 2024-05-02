#include "Joc.h"

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		int x, y, rotacio, iTipus;

		fitxer >> iTipus >> x >> y >> rotacio;

		TipusFigura tTipus = TipusFigura(iTipus);
		ColorFigura tColor;

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

		m_figura.inicialitza(tColor, tTipus);
		m_figura.setPosicioX(x);
		m_figura.setPosicioY(y);

		for (int i = 0; i < rotacio; i++)
		{
			m_figura.giraFigura(GIR_HORARI);
		}

		int input = 0;

		while (!fitxer.eof())
		{
			for (int i = 0; i < MAX_FILA; i++)
				for (int j = 0; j < MAX_COL; j++)
			{
				fitxer >> input;
				m_tauler.setTauler(ColorFigura(input), i, j);
			}
		}

		fitxer.close();
	}
}

void Joc::escriuTauler(const string& nomFitxer)
{

	ColorFigura matriu_final[MAX_ALCADA][MAX_AMPLADA];

	for (int i = 0; i < MAX_ALCADA; i++)
		for (int j = 0; j < MAX_AMPLADA; j++)
	{
		matriu_final[i][j] = m_tauler.getTauler(i, j);
	}

	for (int i = 0; i < m_figura.getTamany(); i++)
		for (int j = 0; j < m_figura.getTamany(); j++)
	{
		if (m_figura.getFigura(i, j) != 0)
		{
			matriu_final[m_figura.getPosicioX() + i][m_figura.getPosicioY() + j] = m_figura.getFigura(i, j);
		}
	}

	ofstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		for (int i = 0; i < MAX_ALCADA; i++)
		{
			for (int j = 0; j < MAX_AMPLADA; j++)
			{
				fitxer << int(matriu_final[i][j]) << " ";
			}
			fitxer << endl;
		}
		fitxer.close();
	}
}

bool Joc::giraFigura(DireccioGir direccio)
{
	bool moviment_valid = true;
	m_figura.giraFigura(direccio);

	if (m_figura.getPosicioX() >= 0 && m_figura.getPosicioX() < MAX_COL)
	{
		for (int i = 0; i < m_figura.getTamany(); i++)
			for (int j = 0; i < m_figura.getTamany(); j++)
		{
			if ((m_figura.getFigura(i, j) != NO_COLOR) && (m_tauler.getTauler(i + m_figura.getPosicioY(), j + m_figura.getPosicioY()) != NO_COLOR))
			{
				moviment_valid = false;
			}
		}
	}

	else
	{
		moviment_valid = false;
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
	bool moviment_valid = true;
	int posicio = m_figura.getPosicioX() + dirX;

	if (posicio >= 0 && posicio + m_figura.getTamany() - 1 < MAX_COL)
	{
		for (int i = 0; i < m_figura.getTamany(); i++)
			for (int j = 0; i < m_figura.getTamany(); j++)
		{
			if ((m_figura.getFigura(i, j) != 0) && (m_tauler.getTauler(i + m_figura.getPosicioY(), j + m_figura.getPosicioY()) != 0))
			{
				moviment_valid = false;
			}
		}
	}

	else
	{
		moviment_valid = false;
	}
	
	if (moviment_valid)
	{
		m_figura.setPosicioX(m_figura.getPosicioX() + dirX);
	}

	return moviment_valid;
}

int Joc::baixaFigura()
{
	bool moviment_valid = true;
	int files_plenes = 0;

	if (m_figura.getPosicioY() >= 0 && m_figura.getPosicioY() + m_figura.getTamany() - 1 < MAX_ALCADA)
	{
		for (int i = 0; i < m_figura.getTamany(); i++)
			for (int j = 0; i < m_figura.getTamany(); j++)
		{
			if ((m_figura.getFigura(i, j) != NO_COLOR) && (m_tauler.getTauler(i + m_figura.getPosicioY(), j + m_figura.getPosicioY()) != NO_COLOR))
			{
				moviment_valid = false;
			}
		}
	}

	else
	{
		moviment_valid = false;
	}

	if (moviment_valid)
	{
		m_figura.setPosicioY(m_figura.getPosicioY() + 1);
	}

	else
	{
		files_plenes = m_tauler.actualitzaTauler(m_figura);
	}

	return files_plenes;
}