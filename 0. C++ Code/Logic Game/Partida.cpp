#include "./Partida.h"

Partida::Partida()
{
    nivell = 1;
    puntuacio = 0;
    m_temps = 0;
}

void Partida::actualitza(const double& deltaTime, const TipusTecla& tecla)
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
        puntua(m_joc.baixaFigura());

    if (Keyboard_GetKeyTrg(KEYBOARD_SPACE))
        while (!puntua(m_joc.baixaFigura())) {}

    m_temps += deltaTime;

    if (m_temps > (0.5/nivell))
    {
        puntua(m_joc.baixaFigura());
        m_temps = 0.0;
    }

    if (puntuacio > 1000 * nivell)
        nivell++;

    m_joc.actualitza();

    string msg = "Puntuacio: " + to_string(puntuacio) + ", Nivell: " + to_string(nivell);
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 80, 1.0, msg);
}

bool Partida::puntua(const int& punts)
{
    bool puntuat = false;
    if (punts != -1)
    {
        m_joc.novaFigura();
        puntuacio += 10;
        switch (punts)
        {
            case 1: puntuacio += 100; break;
            case 2: puntuacio += 250; break;
            case 3: puntuacio += 375; break;
            case 4: puntuacio += 500; break;
        }
        puntuat = true;        
    }
    return puntuat;
}