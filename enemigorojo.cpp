#include "enemigorojo.h"

enemigorojo::enemigorojo(SDL_Renderer* renderer)
{
      this->renderer=renderer;
    textura=IMG_LoadTexture(renderer,"enemigo2.png");
    SDL_QueryTexture(textura, NULL, NULL, &rectangulo.w, &rectangulo.h);
    rectangulo.x = 0;
    rectangulo.y = 0;
}

enemigorojo::~enemigorojo()
{
    //dtor
}

void enemigorojo::dibujar()
{
SDL_RenderCopy(renderer, textura, NULL, &rectangulo);
}

void enemigorojo::logica()
{

if(rectangulo.y<=700)
rectangulo.y++;
if(rectangulo.y==700)
rectangulo.y=0;
}
