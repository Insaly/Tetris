#ifndef JOC_H
#define JOC_H

#include <string>
#include <fstream>

#include "./Tauler.h"
#include "./Figura.h"
#include "./GraphicManager.h"

class Joc
{
public:
	void inicialitza(const string& nomFitxer);
	void actualitza();
	void novaFigura(const Figura& novaFigura) { m_figura = novaFigura; }
	bool giraFigura(const DireccioGir& direccio);
	bool mouFigura(const int& dirX);
	int baixaFigura();
private:
	bool comprovaEspai();
	Tauler m_tauler;
	Figura m_figura;
};

#endif