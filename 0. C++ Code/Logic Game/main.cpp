#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined  (_WIN64)

//Definicio necesaria per poder incloure la llibreria i que trobi el main
#define SDL_MAIN_HANDLED
#include <windows.h>

//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#include <conio.h>      /* getch */ 

#elif __APPLE__

//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <SDL2/SDL.h>
#pragma clang diagnostic pop

#endif

#include "./Tetris.h"

int main(int argc, const char* argv[])
{
    SDL_SetMainReady();
    SDL_Init(SDL_INIT_VIDEO);

    Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);
    Tetris game;

    int opcio = 0, puntuacio = 0;
    string fitxerPartida = "", fitxerFigures = "", fitxerMoviments = "", fitxerPuntuacions = "./data/Games/puntuacions.txt";

    while (opcio != 4)
    {
        opcio = game.mostraMenu();
        system("cls"); 
        switch (opcio)
        {
        case 1:
            game.jugaPartida(fitxerPartida, fitxerFigures, fitxerMoviments, 0, pantalla); break;
        case 2:
            cout << "Nom del fitxer amb l'estat inicial del tauler: ";
            cin >> fitxerPartida;
            cout << "Nom del fitxer amb la sequencia de figures: ";
            cin >> fitxerFigures;
            cout << "Nom del fitxer amb la sequencia de moviments: ";
            cin >> fitxerMoviments;
            fitxerPartida = "./data/Games/" + fitxerPartida;
            fitxerFigures = "./data/Games/" + fitxerFigures;
            fitxerMoviments = "./data/Games/" + fitxerMoviments;
            game.jugaPartida(fitxerPartida, fitxerFigures, fitxerMoviments, 1, pantalla); system("cls"); break;
        case 3:
            game.mostraPuntuacions(fitxerPuntuacions); break;
        }
    }

    SDL_Quit();
    return 0;
}