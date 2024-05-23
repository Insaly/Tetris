#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <string>

#include "./InfoJoc.h"
#include "./Joc.h"
#include "./GraphicManager.h"

using namespace std;

class Partida 
{
public:
    Partida();
    void actualitza(double deltaTime, TipusTecla tecla);
private:
    int puntuacio;
    int nivell;
    int punts;
    double m_temps;
    Joc m_joc;
};

#endif 
