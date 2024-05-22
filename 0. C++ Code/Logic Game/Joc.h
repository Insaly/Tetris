#ifndef JOC_H
#define JOC_H

#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "./Tauler.h"
#include "./Figura.h"
#include "./GraphicManager.h"

using namespace std;

class Joc
{
public:
	Joc() { srand(time(NULL)); int random = (rand() % 7 + 1); m_figura.inicialitza(ColorFigura(random), TipusFigura(random)); m_figura.setPosicioX(3); m_figura.setPosicioY(0); }
	void inicialitza(const string& nomFitxer);
	void actualitza();
	void novaFigura() { int random = (rand() % 7 + 1); m_figura.inicialitza(ColorFigura(random), TipusFigura(random)); m_figura.setPosicioX(3); m_figura.setPosicioY(0); }
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
private:
	bool comprovaEspai();
	Tauler m_tauler;
	Figura m_figura;
};

#endif