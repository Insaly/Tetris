#include "./Partida.h"

Partida::Partida()
{
    puntuacio = 0;
    nivell = 1;
    m_temps = 0;
    punts = 0;
}

void Partida::actualitza(double deltaTime, TipusTecla tecla)
{
    if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT) || tecla == TECLA_DRETA)
        m_joc.mouFigura(1);

    if (Keyboard_GetKeyTrg(KEYBOARD_LEFT) || tecla == TECLA_ESQUERRA)
        m_joc.mouFigura(-1);

    if (Keyboard_GetKeyTrg(KEYBOARD_UP) || tecla == TECLA_AMUNT)
        m_joc.giraFigura(GIR_HORARI);

    if (Keyboard_GetKeyTrg(KEYBOARD_DOWN) || tecla == TECLA_ABAIX)
        m_joc.giraFigura(GIR_ANTI_HORARI);

    if (Keyboard_GetKeyTrg(KEYBOARD_TAB))
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

