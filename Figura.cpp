#include "Figura.h"

Figura::Figura()
{
    color = NO_COLOR;
    tipus = NO_FIGURA;
    posicio_x = 0;
    posicio_y = 0;
    tamany = 0;
    rotacio = 0;

    for (int i = 0; i < MAX_AMPLADA; i++)
        for (int j = 0; j < MAX_ALCADA; j++)
    {
        figura[i][j] = NO_COLOR;
    }
} 

void Figura::inicialitza(ColorFigura n_color, TipusFigura n_figura)
{
    color = n_color;
    tipus = n_figura;

    for (int i = 0; i < MAX_AMPLADA; i++)
        for (int j = 0; j < MAX_ALCADA; j++)
    {
        figura[i][j] = NO_COLOR;
    }

    switch (n_figura)
    {
        case FIGURA_O:
            tamany = 2;
            figura[0][0] = n_color; figura[0][1] = n_color; figura[1][0] = n_color; figura[1][1] = n_color;
            break;
        case FIGURA_I:
            tamany = 4;
            figura[1][0] = n_color; figura[1][1] = n_color; figura[1][2] = n_color; figura[1][3] = n_color;
            break;
        case FIGURA_T:
            tamany = 3;
            figura[0][1] = n_color; figura[1][0] = n_color; figura[1][1] = n_color; figura[1][2] = n_color;
            break;
        case FIGURA_L:
            tamany = 3;
            figura[0][3] = n_color; figura[1][0] = n_color; figura[1][1] = n_color; figura[1][2] = n_color;
            break;
        case FIGURA_J:
            tamany = 3;
            figura[0][0] = n_color; figura[1][0] = n_color; figura[1][1] = n_color; figura[1][2] = n_color;
            break;
        case FIGURA_S:
            tamany = 3;
            figura[0][1] = n_color; figura[0][2] = n_color; figura[1][0] = n_color; figura[1][1] = n_color;
            break;
        case FIGURA_Z:
            tamany = 3;
            figura[0][0] = n_color; figura[0][1] = n_color; figura[1][1] = n_color; figura[1][2] = n_color;
            break;
        default:
            tamany = 4;
    }
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
            rotacio++;
			break;
		case GIR_ANTI_HORARI:
			for (int i = 0; i < tamany; i++)
                for (int j = 0; j < tamany; j++)
            {
                figura[i][j] = figura_aux[tamany-i-1][j];
            }
            rotacio--;
			break;
	}

    switch (rotacio)
	{
        case 4:
            rotacio = 0; break;
        case -1:
            rotacio = 3; break;
    }
}