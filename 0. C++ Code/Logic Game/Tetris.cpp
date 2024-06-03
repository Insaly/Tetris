#include "./Tetris.h"
#include <forward_list>

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

void Tetris::mostraPuntuacions(const string& nomFitxer)
{
    ifstream fitxer;

    fitxer.open(nomFitxer);
    int x;
    cout << "Llista millors puntuacions" << endl;
    cout << "==========================" << endl;
    for (int i = 0; i < 10; i++)
    {
        fitxer >> x;
        cout << i + 1 << " " << x << endl;
    }

}

void Tetris::afegeixPuntuacio(int puntuacio, const string& nomFitxer)
{
    int i = 0;
    ifstream fitxer;
    fitxer.open(nomFitxer);

    if (fitxer.is_open())
    {
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

    while (i <= 10)
    {
        it = puntuacions.begin();
     
        if (i == 10)
        {
            puntuacions.erase_after(it);
        }
        i++;
        it++;
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