#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined  (_WIN64)

#include <iostream>

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
#include "./Partida.h"

int jugant(string fitxerPartida, string fitxerFigures, string fitxerMoviments, Tetris game, int mode)
{
    Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);
    pantalla.show();

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;

    game.inicialitzaPartida(mode, fitxerPartida, fitxerFigures, fitxerMoviments);
 
    do
    {
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

        pantalla.processEvents();

        game.jugaPartida(deltaTime);

        pantalla.update();

    } while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));

    return game.getPuntuacio();
}

int main(int argc, const char* argv[])
{
    SDL_SetMainReady();
    SDL_Init(SDL_INIT_VIDEO);

    Tetris game;

    int opcio = 0, puntuacio = 0;
    string fitxerPartida = "", fitxerFigures = "", fitxerMoviments = "";
    while (opcio != 4)
    {
        opcio = game.mostraMenu();
        system("cls"); 
        switch (opcio)
        {
        case 1:
            puntuacio = jugant(fitxerPartida, fitxerFigures, fitxerMoviments, game, 0); break;
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
            puntuacio = jugant(fitxerPartida, fitxerFigures, fitxerMoviments, game, 1); break;
        case 3:
            game.mostraPuntuacions(); break;
        }
    }

    SDL_Quit();
    return 0;
}