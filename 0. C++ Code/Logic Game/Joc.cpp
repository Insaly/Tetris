#include <iostream>

#include "./Joc.h"

using namespace std;

void Joc::actualitza()
{

	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);

	ColorFigura matriu_final[N_FILES_TAULER][N_COL_TAULER];

	for (int i = 0; i < N_FILES_TAULER; i++)
	{
		for (int j = 0; j < N_COL_TAULER; j++)
		{
			matriu_final[i][j] = m_tauler.getTauler(i, j);
		}
	}

	if (m_figura.getTipus() != NO_FIGURA)
	{
		for (int i = 0; i < m_figura.getTamany(); i++)
			for (int j = 0; j < m_figura.getTamany(); j++)
			{
				if (m_figura.getFigura(i, j) != 0)
				{
					matriu_final[m_figura.getPosicioY() + i][m_figura.getPosicioX() + j] = m_figura.getFigura(i, j);
				}
			}
	}

	for (int i = 0; i < N_FILES_TAULER; i++)
        for (int j = 0; j < N_COL_TAULER; j++)
		{
			IMAGE_NAME color = GRAFIC_NUM_MAX;

			switch(matriu_final[i][j])
			{
				case COLOR_GROC: color = GRAFIC_QUADRAT_GROC; break;
				case COLOR_BLAUCEL: color = GRAFIC_QUADRAT_BLAUCEL; break;
				case COLOR_MAGENTA: color = GRAFIC_QUADRAT_MAGENTA; break;
				case COLOR_TARONJA: color = GRAFIC_QUADRAT_TARONJA; break;
				case COLOR_BLAUFOSC: color = GRAFIC_QUADRAT_BLAUFOSC; break;
				case COLOR_VERMELL: color = GRAFIC_QUADRAT_VERMELL; break;
				case COLOR_VERD: color = GRAFIC_QUADRAT_VERD; break;
			}

			if (color != GRAFIC_NUM_MAX)
				GraphicManager::getInstance()->drawSprite(color, POS_X_TAULER + ((j + 1) * MIDA_QUADRAT), POS_Y_TAULER + ((i)*MIDA_QUADRAT), false);
		}

	string msg = "Fila: " + to_string(m_figura.getPosicioY()) + ", Columna: " + to_string(m_figura.getPosicioX());
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 50, 1.0, msg);
}

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		m_figura.inicialitza(COLOR_NEGRE, NO_FIGURA);
		int y, x, rotacio, iTipus;

		fitxer >> iTipus >> y >> x >> rotacio;

		TipusFigura tTipus = TipusFigura(iTipus);
		ColorFigura tColor = NO_COLOR;

		switch (tTipus)
		{
		case FIGURA_O:
			tColor = COLOR_GROC; break;
		case FIGURA_I:
			tColor = COLOR_BLAUCEL; break;
		case FIGURA_T:
			tColor = COLOR_MAGENTA; break;
		case FIGURA_L:
			tColor = COLOR_TARONJA; break;
		case FIGURA_J:
			tColor = COLOR_BLAUFOSC; break;
		case FIGURA_Z:
			tColor = COLOR_VERMELL; break;
		case FIGURA_S:
			tColor = COLOR_VERD; break;
		}

		m_figura.inicialitza(tColor, tTipus);
		m_figura.setPosicioX(x - 1);
		m_figura.setPosicioY(y - 1);

		for (int i = 0; i < rotacio; i++)
		{
			m_figura.giraFigura(GIR_HORARI);
		}

		int input = 0, n = 0;

		while (!fitxer.eof() && n < N_FILES_TAULER)
		{
			for (int i = 0; i < N_FILES_TAULER; i++)
			{
				for (int j = 0; j < N_COL_TAULER; j++)
				{
					fitxer >> input;
					m_tauler.setTauler(ColorFigura(input), i, j);
				}
				n++;
			}
		}

		fitxer.close();
	}
}

void Joc::escriuTauler(const string& nomFitxer)
{

	ColorFigura matriu_final[N_FILES_TAULER][N_COL_TAULER];

	for (int i = 0; i < N_FILES_TAULER; i++)
	{
		for (int j = 0; j < N_COL_TAULER; j++)
		{
			matriu_final[i][j] = m_tauler.getTauler(i, j);
		}
	}

	if (m_figura.getTipus() != NO_FIGURA)
	{
		for (int i = 0; i < m_figura.getTamany(); i++)
			for (int j = 0; j < m_figura.getTamany(); j++)
			{
				if (m_figura.getFigura(i, j) != 0)
				{
					matriu_final[m_figura.getPosicioY() + i][m_figura.getPosicioX() + j] = m_figura.getFigura(i, j);
				}
			}
	}

	ofstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		for (int i = 0; i < N_FILES_TAULER; i++)
		{
			for (int j = 0; j < N_COL_TAULER; j++)
			{
				fitxer << matriu_final[i][j] << " ";
			}
			fitxer << endl;
		}
		fitxer.close();
	}
}

bool Joc::comprovaEspai()
{
	bool moviment_valid = true;
	ColorFigura tauler_aux[N_FILES_TAULER + 4][N_COL_TAULER + 4];

	for (int i = 0; i < N_FILES_TAULER + 4; i++)
	{
		tauler_aux[i][0] = NO_COLOR;
		tauler_aux[i][1] = NO_COLOR;
		tauler_aux[i][N_COL_TAULER + 2] = NO_COLOR;
		tauler_aux[i][N_COL_TAULER + 3] = NO_COLOR;
	}

	for (int j = 0; j < N_COL_TAULER + 4; j++)
	{
		tauler_aux[0][j] = NO_COLOR;
		tauler_aux[1][j] = NO_COLOR;
		tauler_aux[N_FILES_TAULER + 2][j] = NO_COLOR;
		tauler_aux[N_FILES_TAULER + 3][j] = NO_COLOR;
	}

	for (int i = 2; i < N_FILES_TAULER + 2; i++)
		for (int j = 2; j < N_COL_TAULER + 2; j++)
		{
			tauler_aux[i][j] = m_tauler.getTauler(i - 2, j - 2);
		}

	for (int i = 0; i < m_figura.getTamany(); i++)
		for (int j = 0; j < m_figura.getTamany(); j++)
		{
			if (m_figura.getFigura(i, j) != COLOR_NEGRE)
			{
				if (tauler_aux[m_figura.getPosicioY() + i + 2][m_figura.getPosicioX() + j + 2] != COLOR_NEGRE)
				{
					moviment_valid = false;
				}
			}
		}

	return moviment_valid;
}

bool Joc::giraFigura(DireccioGir direccio)
{
	m_figura.giraFigura(direccio);
	bool moviment_valid = comprovaEspai();

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
	m_figura.setPosicioX(m_figura.getPosicioX() + dirX);
	bool moviment_valid = comprovaEspai();

	if (!moviment_valid)
	{
		m_figura.setPosicioX(m_figura.getPosicioX() - dirX);
	}

	return moviment_valid;
}

int Joc::baixaFigura()
{
	m_figura.setPosicioY(m_figura.getPosicioY() + 1);
	bool moviment_valid = comprovaEspai();
	int files_plenes = -1;

	if (!moviment_valid)
	{
		m_figura.setPosicioY(m_figura.getPosicioY() - 1);
		files_plenes = m_tauler.actualitzaTauler(m_figura);
		m_figura.inicialitza(COLOR_NEGRE, NO_FIGURA);
	}

	return files_plenes;
}