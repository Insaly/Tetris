#ifndef FIGURA_H
#define FIGURA_H

typedef enum
{
    NO_COLOR = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    COLOR_NEGRE,
} ColorFigura;


typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
} TipusFigura;

const int MAX_AMPLADA = 4;
const int MAX_ALCADA = 4;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
    Figura(ColorFigura n_color, TipusFigura n_figura);
    void giraFigura(const DireccioGir& direccio);

    void setPosicioX(int x) { posicio_x = x; }
    void setPosicioY(int y) { posicio_y = y; }
    int getPosicioX() const { return posicio_x; }
    int getPosicioY() const { return posicio_y; }
    int getTamany() const { return tamany; }
    int getRotacio() const { return rotacio; }
    ColorFigura getFigura(int x, int y) const { return figura[x][y]; }
    ColorFigura getColor() const { return color; }
    TipusFigura getTipus() const { return tipus; }
    
private:
    ColorFigura color;
    TipusFigura tipus;
    int posicio_x;
    int posicio_y;
    int tamany;
    int rotacio;
    ColorFigura figura[MAX_AMPLADA][MAX_ALCADA];
};


#endif
