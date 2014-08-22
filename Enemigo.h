#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
class Enemigo
{
    public:
        SDL_Renderer* renderer;
        SDL_Texture* textura;
        SDL_Rect rectangulo;
        Enemigo(SDL_Renderer* renderer);


        Enemigo(){}
        void dibujar();
       virtual void logica();
        virtual ~Enemigo();
    protected:
    private:
};

#endif // ENEMIGO_H
