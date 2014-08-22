#ifndef ENEMIGONEGRO_H
#define ENEMIGONEGRO_H
#include "Enemigo.h"
#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
class enemigonegro
{
    public:


        SDL_Renderer* renderer;
        SDL_Texture* textura;
        SDL_Rect rectangulo;
        enemigonegro(SDL_Renderer* renderer);
        virtual ~enemigonegro();
         void dibujar();
        void logica();

    protected:
    private:
};

#endif // ENEMIGONEGRO_H
