#ifndef TETRIS_H
#define TETRIS_H

#include <iostream>
#include <forward_list>

#include "./Partida.h"

class Tetris
{
public:
    int mostraMenu();
    void mostraPuntuacions(const string& nomFitxer);
    void jugaPartida(string fitxerPartida, string fitxerFigures, string fitxerMoviments, int mode, Screen& pantalla);

    void inicialitzaPartida(int mode, const string& fitxerPartida, const string& fitxerFigures, const string& fitxerMoviments) { m_partida.inicialitza(mode, fitxerPartida, fitxerFigures, fitxerMoviments); }	
    int getPuntuacio() { return puntuacio; }
    void afegeixPuntuacio(int puntuacio, const string& nomFitxer);
private:
    Partida m_partida;
    int puntuacio;
    std::forward_list <int> puntuacions;
    std::forward_list <int> :: iterator actual,it;
};

#endif 
