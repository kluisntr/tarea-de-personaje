#include "enemigonegro.h"

enemigonegro::enemigonegro(SDL_Renderer* renderer)
{
    this->renderer=renderer;
    textura=IMG_LoadTexture(renderer,"enemigo3.png");
    SDL_QueryTexture(textura, NULL, NULL, &rectangulo.w, &rectangulo.h);
    rectangulo.x = 0;
    rectangulo.y = 0;
}

enemigonegro::~enemigonegro()
{
    //dtor
}
void enemigonegro::dibujar()
{
SDL_RenderCopy(renderer, textura, NULL, &rectangulo);
}

void enemigonegro::logica()
{
bool estado=false;
if(rectangulo.y<=300){
rectangulo.x++;
rectangulo.y++;
estado=false;
}else
{
rectangulo.y=350;
estado=true;
}

if(rectangulo.y>=320)
{
rectangulo.y--;
rectangulo.x++;}
else
{
estado=false;
if(estado==true&&rectangulo.x<400)
{
rectangulo.x=0;
rectangulo.y=0;
}

}
}
