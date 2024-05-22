#include "./Partida.h"

#include <string>
#include <iostream>

Partida::Partida()
{
    puntuacio = 0;
    nivell = 1;
    m_temps = 0;
    punts = 0;
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
    {
        punts = m_joc.baixaFigura();
        if (punts != -1)
        {
            m_joc.novaFigura();
            puntuacio += punts;
        }
    }

    if (Keyboard_GetKeyTrg(KEYBOARD_SPACE))
    {
        do {
            punts = m_joc.baixaFigura();
        } while (punts == -1);
        m_joc.novaFigura();
        puntuacio += punts;
    }

    m_temps += deltaTime;

    if (m_temps > (0.5/nivell))
    {
        punts = m_joc.baixaFigura();
        if (punts != -1)
        {
            m_joc.novaFigura();
            puntuacio += punts;
        }
        m_temps = 0.0;
    }

    m_joc.actualitza();

    string msg = "Puntuacio: " + to_string(puntuacio);
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 80, 1.0, msg);
}

