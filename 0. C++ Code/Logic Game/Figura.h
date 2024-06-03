#ifndef FIGURA_H
#define FIGURA_H

#include "./InfoJoc.h"

const int MAX_AMPLADA = 4;
const int MAX_ALCADA = 4;

class Figura
{
public:
    Figura();
    Figura(TipusFigura n_figura, int n_y, int n_x, int n_gir);
    void giraFigura(const DireccioGir& direccio);

    void setPosicioX(const int& x) { posicio_x = x; }
    void setPosicioY(const int& y) { posicio_y = y; }
    int getPosicioX() const { return posicio_x; }
    int getPosicioY() const { return posicio_y; }
    int getTamany() const { return tamany; }
    ColorFigura getFigura(int x, int y) const { return figura[x][y]; }
    ColorFigura getColor() const { return color; }
    TipusFigura getTipus() const { return tipus; }
    
private:
    ColorFigura color;
    TipusFigura tipus;
    int posicio_x;
    int posicio_y;
    int tamany;
    ColorFigura figura[MAX_AMPLADA][MAX_ALCADA];
};

#endif