#include "./Tetris.h"

int Tetris::mostraMenu()
{
    int opcio;
    cout << "MENU PRINCIPAL" << endl;
    cout << "==============" << endl;
    cout << "1. Joc en mode normal" << endl;
    cout << "2. Joc en mode test" << endl;
    cout << "3. Mostrar puntuacions" << endl;
    cout << "4. Sortir" << endl;
    cin >> opcio;
    return opcio;
}

void Tetris::mostraPuntuacions()
{
    string nomFitxer;
    cout << "Introdueix fitxer de puntuacions: ";
    cin >> nomFitxer;
}