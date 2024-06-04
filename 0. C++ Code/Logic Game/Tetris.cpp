#include "./Tetris.h"

int Tetris::mostraMenu()
{
    int opcio;
    cout << "==========================" << endl;
    cout << "Menu principal" << endl;
    cout << "==========================" << endl;
    cout << "1. Joc en mode normal" << endl;
    cout << "2. Joc en mode test" << endl;
    cout << "3. Mostrar puntuacions" << endl;
    cout << "4. Sortir" << endl;
    cin >> opcio;
    return opcio;
}

void Tetris::jugaPartida(string fitxerPartida, string fitxerFigures, string fitxerMoviments, int mode, Screen& pantalla)
{
    pantalla.show();

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;

    m_partida.inicialitza(mode, fitxerPartida, fitxerFigures, fitxerMoviments);

    do
    {
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
        pantalla.processEvents();
        m_partida.actualitza(deltaTime);
        pantalla.update();

    } while (!m_partida.getQuit());
}

void Tetris::mostraPuntuacions(const string& nomFitxer)
{
    ifstream fitxer;

    fitxer.open(nomFitxer);
    system("cls"); 
    int x, i = 0;
    cout << "==========================" << endl;
    cout << "Llista millors puntuacions" << endl;
    cout << "=========================="<< endl;
    while (!fitxer.eof())
    {
        fitxer >> x;
        puntuacions.push_front(x);
    }

    puntuacions.sort(std::greater <int>());
    actual = puntuacions.begin();
    it = puntuacions.end();
    while (actual != it)
    {
        
        cout << i + 1 << ". " <<  *it << endl;
        it++;
        i++;
    }

}

void Tetris::afegeixPuntuacio(int puntuacio, const string& nomFitxer)
{
    int i = 0;
    ifstream fitxer;
    fitxer.open(nomFitxer);


    if (fitxer.is_open())
    {
        puntuacions.clear();
        int x;
        
        while (!fitxer.eof() )
        {
            fitxer >> x;
            puntuacions.push_front(x);   
        }
        fitxer.close();
    }
    puntuacions.push_front(puntuacio);

    puntuacions.sort(std::greater <int>());

    while (distance(puntuacions.begin(), puntuacions.end()) > 10) 
    {
        puntuacions.pop_front();
    }

    ofstream fitxer1;

    fitxer1.open(nomFitxer);

    if (fitxer.is_open())
    {
        for (it=puntuacions.begin(); it != puntuacions.end(); it++)
        {
            int puntuacio = *it;
            fitxer1 << puntuacio << endl;

        }
        fitxer.close();
    }
}