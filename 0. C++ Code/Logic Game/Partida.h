#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <string>

#include "./InfoJoc.h"
#include "./Joc.h"
#include "./GraphicManager.h"

class Partida 
{
public:
    Partida();
    void actualitza(const double& deltaTime, const TipusTecla& tecla);
private:
    bool puntua(const int& punts);
    int puntuacio;
    int nivell;
    double m_temps;
    Joc m_joc;
};

#endif 
