#include "./Figura.h"

Figura::Figura()
{
    color = COLOR_NEGRE;
    tipus = NO_FIGURA;
    posicio_x = 0;
    posicio_y = 0;
    tamany = 0;

    for (int i = 0; i < MAX_AMPLADA; i++)
        for (int j = 0; j < MAX_ALCADA; j++)
    {
        figura[i][j] = COLOR_NEGRE;
    }
} 

Figura::Figura(TipusFigura n_figura, int n_y, int n_x, int n_gir)
{
    posicio_x = n_x;
    posicio_y = n_y;
    color = ColorFigura(n_figura);
    tipus = n_figura;

    for (int i = 0; i < MAX_AMPLADA; i++)
        for (int j = 0; j < MAX_ALCADA; j++)
            figura[i][j] = COLOR_NEGRE;

    switch (n_figura)
    {
        case FIGURA_O:
            tamany = 2;
            figura[0][0] = color; figura[0][1] = color; figura[1][0] = color; figura[1][1] = color;
            break;
        case FIGURA_I:
            tamany = 4;
            figura[1][0] = color; figura[1][1] = color; figura[1][2] = color; figura[1][3] = color;
            break;
        case FIGURA_T:
            tamany = 3;
            figura[0][1] = color; figura[1][0] = color; figura[1][1] = color; figura[1][2] = color;
            break;
        case FIGURA_L:
            tamany = 3;
            figura[0][2] = color; figura[1][0] = color; figura[1][1] = color; figura[1][2] = color;
            break;
        case FIGURA_J:
            tamany = 3;
            figura[0][0] = color; figura[1][0] = color; figura[1][1] = color; figura[1][2] = color;
            break;
        case FIGURA_S:
            tamany = 3;
            figura[0][1] = color; figura[0][2] = color; figura[1][0] = color; figura[1][1] = color;
            break;
        case FIGURA_Z:
            tamany = 3;
            figura[0][0] = color; figura[0][1] = color; figura[1][1] = color; figura[1][2] = color;
            break;
        default:
            tamany = 4;
    }

    for (int i = 0; i < n_gir; i++)
        giraFigura(GIR_HORARI);
}

void Figura::giraFigura(const DireccioGir& direccio)
{
	ColorFigura figura_aux[MAX_ALCADA][MAX_AMPLADA];

    for (int i = 0; i < tamany; i++)
        for (int j = 0; j < tamany; j++)
        {
            figura_aux[i][j] = figura[j][i];
        }

	switch (direccio)
	{
		case GIR_HORARI:
			for (int i = 0; i < tamany; i++)
                for (int j = 0; j < tamany; j++)
            {
                figura[i][j] = figura_aux[i][tamany-j-1];
            }
			break;
		case GIR_ANTI_HORARI:
			for (int i = 0; i < tamany; i++)
                for (int j = 0; j < tamany; j++)
            {
                figura[i][j] = figura_aux[tamany-i-1][j];
            }
			break;
	}
}