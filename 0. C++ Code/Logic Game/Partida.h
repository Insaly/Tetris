#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

#include "./InfoJoc.h"
#include "./Joc.h"
#include "./GraphicManager.h"

class NodeFigura
{
public:
    Figura getValor(){ return m_figura; }
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
    NodeFigura& getPrimer() const { if (!esBuida()) { return *m_primer; } };
    NodeFigura& getUltim() const { if (!esBuida()) { return *m_ultim; } };
    bool esBuida() const { return m_primer == nullptr; }
private:
    NodeFigura* m_primer;
    NodeFigura* m_ultim;
}; 

class Partida 
{
public:
    Partida();
    void inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);
    void actualitza(const double& deltaTime);
private:
    bool puntua(const int& punts);
    int puntuacio;
    int nivell;
    int m_mode;
    double m_temps;
    Joc m_joc;
    CuaFigura m_cua;
};

#endif 
