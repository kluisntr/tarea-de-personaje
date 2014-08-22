#ifndef ENEMIGOROJO_H
#define ENEMIGOROJO_H
#include "Enemigo.h"
#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
class enemigorojo
{
    public:
        enemigorojo();
        SDL_Renderer* renderer;
        SDL_Texture* textura;
        SDL_Rect rectangulo;
        enemigorojo(SDL_Renderer* renderer);
        virtual ~enemigorojo();
         void dibujar();
        void logica();


    protected:
    private:
};

#endif // ENEMIGOROJO_H
