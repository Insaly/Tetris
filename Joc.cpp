#include "Joc.h"
#include <iostream>
using namespace std;

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
		ColorFigura tColor;

		x--; y--;

		switch (tTipus)
		{
			case FIGURA_O:
				tColor = COLOR_GROC; break;
			case FIGURA_I:
				tColor = COLOR_BLAUCEL;
				switch (rotacio)
				{
					case 0: x--; break;
					case 1: x--; y--; break;
					case 2: y--; break;
				}
				break;
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
		m_figura.setPosicioX(x);
		m_figura.setPosicioY(y);

		for (int i = 0; i < rotacio; i++)
		{
			m_figura.giraFigura(GIR_HORARI);
		}

		int input = 0, n = 0;

		while (!fitxer.eof() && n < MAX_FILA)
		{
			for (int i = 0; i < MAX_FILA; i++)
			{
				for (int j = 0; j < MAX_COL; j++)
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

	ColorFigura matriu_final[MAX_FILA][MAX_COL];

	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
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
		for (int i = 0; i < MAX_FILA; i++)
		{
			for (int j = 0; j < MAX_COL; j++)
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
	bool moviment_valid = true, dintre_limits;

	for (int i = 0; i < m_figura.getTamany(); i++)
		for (int j = 0; j < m_figura.getTamany(); j++)
	{
		if (m_figura.getFigura(i, j) != COLOR_NEGRE)
		{
			if (m_tauler.getTauler(i + m_figura.getPosicioY(), j + m_figura.getPosicioX()) != COLOR_NEGRE)
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
	int files_plenes = 0;

	if (!moviment_valid)
	{
		m_figura.setPosicioY(m_figura.getPosicioY() - 1);
		files_plenes = m_tauler.actualitzaTauler(m_figura);
		m_figura.inicialitza(COLOR_NEGRE, NO_FIGURA);
	}

	return files_plenes;
}