#ifndef TETRIS_H
#define TETRIS_H

#include "./Partida.h"
#include <iostream>

class Tetris
{
public:
    int mostraMenu();
    void mostraPuntuacions();
    void jugaPartida(double deltaTime) { m_partida.actualitza(deltaTime); }
    void inicialitzaPartida(int mode, const string& fitxerPartida, const string& fitxerFigures, const string& fitxerMoviments) { m_partida.inicialitza(mode, fitxerPartida, fitxerFigures, fitxerMoviments); }	
    int getPuntuacio() { return puntuacio; }
private:
    Partida m_partida;
    int puntuacio;
};

#endif 
