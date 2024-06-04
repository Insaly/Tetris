#ifndef TETRIS_H
#define TETRIS_H

#include <iostream>
#include <forward_list>

#include "./Partida.h"

struct Puntuacions
{
    int puntuacio = 0;
    string nom = " ";
};

class Tetris
{
public:
    int mostraMenu();
    void mostraPuntuacions(const string& nomFitxer);
    int jugaPartida(string fitxerPartida, string fitxerFigures, string fitxerMoviments, int mode, Screen& pantalla);

    void inicialitzaPartida(int mode, const string& fitxerPartida, const string& fitxerFigures, const string& fitxerMoviments) { m_partida.inicialitza(mode, fitxerPartida, fitxerFigures, fitxerMoviments); }	
    void afegeixPuntuacio(int puntuacio, const string& nomFitxer, const string& nom);
private:
    Partida m_partida;
    Puntuacions puntuacio;
    std::forward_list <Puntuacions> puntuacions;
    std::forward_list <Puntuacions> :: iterator actual,it;
};

#endif 
