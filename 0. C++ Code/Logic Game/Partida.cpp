#include "./Partida.h"

Partida::Partida()
{
    srand(time(NULL));
    game_over = false;
    quit = false;
    nivell = 1;
    puntuacio = 0;
    m_mode = 0;
    m_temps = 0;
}

void Partida::inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments)
{
    m_mode = mode;
    m_joc = Joc();
    m_cua = CuaFigura();
    m_moviments = CuaTecla();
    srand(time(NULL));
    game_over = false;
    quit = false;
    nivell = 1;
    puntuacio = 0;
    m_mode = mode;
    m_temps = 0;

    if (mode == 1)
    {
        m_joc.inicialitza(fitxerInicial);

        fstream fitxer;
        fitxer.open(fitxerFigures);
        if (fitxer.is_open())
        {
            int tipus, fila, columna, gir;
            while (fitxer >> tipus >> fila >> columna >> gir)
                m_cua.afegeix(Figura(TipusFigura(tipus), fila, columna, gir));
            fitxer.close();
        }
        
        fitxer.open(fitxerMoviments);
        if (fitxer.is_open())
        {
            int moviment;
            while (fitxer >> moviment)
                m_moviments.afegeix(TipusTecla(moviment));
            fitxer.close();
        }
    }
    else
    {
        m_joc.novaFigura(Figura(TipusFigura(rand() % 7 + 1), 1, 1, 0));
        m_cua.afegeix(Figura(TipusFigura(rand() % 7 + 1), 1, 1, 0));
    }
}

void Partida::actualitza(const double& deltaTime)
{
    m_temps += deltaTime;

    if (!game_over)
    {
        TipusTecla tecla = NO_TECLA;

        if (m_temps > (0.5 / nivell))
        {
            switch (m_mode)
            {
            case 0:
                puntua(m_joc.baixaFigura());
                break;
            case 1:
                if (!m_moviments.esBuida() && m_moviments.getPrimer() != nullptr && m_moviments.getTamany() > 0)
                {
                    tecla = m_moviments.getPrimer()->getValor();
                    m_moviments.treu();
                }
                else
                {
                    game_over = true;
                }
                break;
            }
            m_temps = 0.0;
        }

        if (puntuacio > 1000 * nivell)
            nivell++;

        if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT) || tecla == TECLA_DRETA)
            m_joc.mouFigura(1);

        if (Keyboard_GetKeyTrg(KEYBOARD_LEFT) || tecla == TECLA_ESQUERRA)
            m_joc.mouFigura(-1);

        if (Keyboard_GetKeyTrg(KEYBOARD_UP) || tecla == TECLA_AMUNT)
            m_joc.giraFigura(GIR_HORARI);

        if (Keyboard_GetKeyTrg(KEYBOARD_DOWN) || tecla == TECLA_ABAIX)
            m_joc.giraFigura(GIR_ANTI_HORARI);

        if (Keyboard_GetKeyTrg(KEYBOARD_TAB) || tecla == TECLA_ESPAI)
            puntua(m_joc.baixaFigura());

        if (Keyboard_GetKeyTrg(KEYBOARD_SPACE) || tecla == TECLA_ESCAPE)
            while (!puntua(m_joc.baixaFigura())) {}
        
        if (Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && !game_over)
            game_over = true;

        m_joc.actualitza();

        string msgStats = "Puntuacio: " + to_string(puntuacio) + ", Nivell: " + to_string(nivell);
        GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 80, 1.0, msgStats);
    }
    else
    {
        GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
        string msgGameOver = "GAME OVER!";
        string msgPuntuacio = "Puntuació final: " + to_string(puntuacio);
        string msgSortir = "Prem 'ESC' per a tornar al menú";
        GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER - 10, POS_Y_TAULER + 100, 2.0, msgGameOver);
        GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER + 30, POS_Y_TAULER + 200, 1.0, msgPuntuacio);
        if (m_temps > 1)
            GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER - 35, POS_Y_TAULER + 350, 1.0, msgSortir);
        if (m_temps > 2)
            m_temps = 0;

        if (Keyboard_GetKeyTrg(KEYBOARD_ESCAPE))
            quit = true;
    }
}

bool Partida::puntua(const int& punts)
{
    bool puntuat = false;
    if (punts != -1)
    {
        if (m_mode == 0)
        {
            m_cua.afegeix(Figura(TipusFigura(rand() % 7 + 1), 1, 1, 0));
        }

        m_joc.novaFigura(m_cua.getPrimer()->getValor());
        m_cua.treu();
        if (!m_joc.comprovaEspai())
            game_over = true;
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

void CuaFigura::afegeix(Figura valor)
{
    NodeFigura* nou = new NodeFigura;
    nou->setValor(valor);
    if (esBuida())
    {
        m_primer = nou;
        m_ultim = nou;
    }
    else
    {
        m_ultim->setSeguent(nou);
        m_ultim = nou;
    }
}

void CuaFigura::treu()
{
    if (!esBuida())
    {
        NodeFigura* aux = m_primer;
        m_primer = m_primer->getSeguent();
        delete aux;
        if (m_primer == nullptr)
            m_ultim = nullptr;
    }
}

void CuaTecla::afegeix(TipusTecla valor)
{
    NodeTecla* nou = new NodeTecla;
    nou->setValor(valor);
    if (esBuida())
    {
        m_primer = nou;
        m_ultim = nou;
    }
    else
    {
        m_ultim->setSeguent(nou);
        m_ultim = nou;
    }
    tamany++;
}

void CuaTecla::treu()
{
    if (!esBuida())
    {
        NodeTecla* aux = m_primer;
        m_primer = m_primer->getSeguent();
        delete aux;
        if (m_primer == nullptr)
            m_ultim = nullptr;
    }
    tamany--;
}