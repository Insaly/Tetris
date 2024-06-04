#include "./Tetris.h"

bool comparar(const Puntuacions& a, const Puntuacions& b)
{
    return a.puntuacio > b.puntuacio;
}

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

int Tetris::jugaPartida(string fitxerPartida, string fitxerFigures, string fitxerMoviments, int mode, Screen& pantalla)
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

    return m_partida.getPuntuacio();
}

void Tetris::mostraPuntuacions(const string& nomFitxer)
{
    ifstream fitxer;

    fitxer.open(nomFitxer);
    system("cls"); 

    cout << "==========================" << endl;
    cout << "Llista millors puntuacions" << endl;
    cout << "=========================="<< endl;

    puntuacions = std::forward_list<Puntuacions>();
    Puntuacions x;
    while (fitxer >> x.nom >> x.puntuacio)
    {
        puntuacions.push_front(x);
        Puntuacions x;
    }

    puntuacions.sort(comparar);
    
    actual = puntuacions.begin();
    it = puntuacions.end();

    int i = 0;

    while (actual != it && i < 10)
    {
        Puntuacions puntuacio = *actual;
        cout << i + 1 << ". " << puntuacio.nom  << " " << puntuacio.puntuacio << endl;
        actual++;
        i++;
    }

}

void Tetris::afegeixPuntuacio(int puntuacio, const string& nomFitxer, const string& nom)
{
    ofstream fitxer;
    fitxer.open(nomFitxer, ofstream::app);

    if (fitxer.is_open())
    {
        fitxer << nom << " " << to_string(puntuacio) << endl;
        fitxer.close();
    }
}