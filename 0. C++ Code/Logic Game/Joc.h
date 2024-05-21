#ifndef JOC_H
#define JOC_H

#include <string>
#include <fstream>

#include "./Tauler.h"
#include "./Figura.h"
#include "./GraphicManager.h"

using namespace std;

class Joc
{
public:
	Joc() { m_figura.inicialitza(COLOR_MAGENTA, FIGURA_O); m_figura.setPosicioX(3); m_figura.setPosicioY(0); }
	void inicialitza(const string& nomFitxer);
	void actualitza();
	void novaFigura() { m_figura.inicialitza(COLOR_TARONJA, FIGURA_L); m_figura.setPosicioX(3), m_figura.setPosicioY(0); }
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);
private:
	bool comprovaEspai();
	Tauler m_tauler;
	Figura m_figura;
};

#endif