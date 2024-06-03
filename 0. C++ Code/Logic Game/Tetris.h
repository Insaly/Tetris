#ifndef TETRIS_H
#define TETRIS_H

#include "./Partida.h"
#include <iostream>
#include <forward_list>

class Tetris
{
public:
    int mostraMenu();
    void mostraPuntuacions(const string& nomFitxer);
    void jugaPartida(double deltaTime) { m_partida.actualitza(deltaTime); }
    void inicialitzaPartida(int mode, const string& fitxerPartida, const string& fitxerFigures, const string& fitxerMoviments) { m_partida.inicialitza(mode, fitxerPartida, fitxerFigures, fitxerMoviments); }	
    int getPuntuacio() { return puntuacions; }
    void afegeixPuntuacio(int puntuacio, const string& nomFitxer);
private:
    Partida m_partida;
    int puntuacions;
    std::forward_list <int> puntuacions;
    std::forward_list <int> :: iterator actual,it;
};

#endif 
