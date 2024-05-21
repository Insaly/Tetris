#include "./Partida.h"

#include <string>
#include <iostream>

Partida::Partida()
{
    puntuacio = 0;
    nivell = 1;
    m_temps = 0;
}

void Partida::actualitza(double deltaTime)
{
    if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
        m_joc.mouFigura(1);

    if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
        m_joc.mouFigura(-1);

    if (Keyboard_GetKeyTrg(KEYBOARD_A))
        m_joc.giraFigura(GIR_HORARI);

    if (Keyboard_GetKeyTrg(KEYBOARD_B))
        m_joc.giraFigura(GIR_ANTI_HORARI);

    if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
        if (m_joc.baixaFigura() != -1)
            m_joc.novaFigura();

    if (Keyboard_GetKeyTrg(KEYBOARD_SPACE))
    {
        while (m_joc.baixaFigura() == -1) {}
            m_joc.novaFigura();
    }

    m_temps += deltaTime;

    if (m_temps > (0.5/nivell))
    {
        if (m_joc.baixaFigura() != -1)
            m_joc.novaFigura();
        m_temps = 0.0;
    }

    m_joc.actualitza();
}

