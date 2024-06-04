#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "./Joc.h"

class NodeFigura
{
public:
    Figura getValor() const { return m_figura; }
    NodeFigura* getSeguent() const { return m_seguent; }
    void setValor(const Figura& valor) { m_figura = valor; }
    void setSeguent(NodeFigura* seguent) { m_seguent = seguent; }
private:
    Figura m_figura;
    NodeFigura* m_seguent;
};

class CuaFigura
{
public:
    CuaFigura() : m_primer(nullptr), m_ultim(nullptr) {}
    void afegeix(Figura valor);
    void treu();
    NodeFigura* getPrimer() const { return m_primer; };
    NodeFigura* getUltim() const { return m_ultim; };
    bool esBuida() const { return m_primer == nullptr; }
private:
    NodeFigura* m_primer;
    NodeFigura* m_ultim;
}; 

class NodeTecla
{
public:
    TipusTecla getValor() const { return m_moviment; }
    NodeTecla* getSeguent() const { return m_seguent; }
    void setValor(const TipusTecla& valor) { m_moviment = valor; }
    void setSeguent(NodeTecla* seguent) { m_seguent = seguent; }
private:
    TipusTecla m_moviment;
    NodeTecla* m_seguent;
};

class CuaTecla
{
public:
    CuaTecla() : m_primer(nullptr), m_ultim(nullptr), tamany(0) {}
    void afegeix(TipusTecla valor);
    void treu();
    NodeTecla* getPrimer() const { return m_primer; };
    NodeTecla* getUltim() const { return m_ultim; };
    int getTamany() const { return tamany; }
    bool esBuida() const { return m_primer == nullptr; }
private:
    NodeTecla* m_primer;
    NodeTecla* m_ultim;
    int tamany;
}; 

class Partida 
{
public:
    Partida();
    void inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);
    void actualitza(const double& deltaTime);
    bool getQuit() const { return quit; }
    int getPuntuacio() const { return puntuacio; }
private:
    bool puntua(const int& punts);
    bool game_over;
    bool quit;
    int puntuacio;
    int nivell;
    int m_mode;
    double m_temps;
    Joc m_joc;
    CuaFigura m_cua;
    CuaTecla m_moviments;
};

#endif 
