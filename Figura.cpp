#include "Figura.h"

Figura::Figura(ColorFigura n_color, TipusFigura n_figura)
{
    
}

void Figura::giraFigura(const DireccioGir& direccio)
{
    int amplada, alcada;

    switch (tipus)
    {
        case FIGURA_I:
            amplada = 4;
            alcada = 4;
            break;

        case FIGURA_O:
            amplada = 2;
            alcada = 2;
            break;

        default:
            amplada = 3;
            alcada = 3;
    }

	ColorFigura f_aux[amplada][alcada] = figura;
	ColorFigura f[amplada][alcada];

	for(int i = 0; i < amplada; i++)
        for(int j = 0; j < alcada; j++)
		{
            f[i][j] = f_aux[j][i];
        }

	switch (direccio)
	{
		case GIR_HORARI:
			for (int i = 0; i < amplada; i++)
                for (int j = 0; j < alcada; j++)
                {
                    f_aux[i][j] = f[i][amplada-j];
                }
			break;
		case GIR_ANTI_HORARI:
			for (int i = 0; i < amplada; i++)
                for (int j = 0; j < alcada; j++)
                {
                    f_aux[i][j] = f[alcada-i][j];
                }
			break;
	}

    figura = f_aux;
}