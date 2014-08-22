#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mixer.h>
#include<iostream>
#include "Enemigo.h"
#include  "enemigorojo.h"
#include  "enemigonegro.h"
using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character1, *character2,*character3,*character4,*character5,*character6,*character7,*character8, *character_otro;
SDL_Rect rect_background,rect_character, rect_character_otro;
Mix_Music *musica = NULL;


bool colision(SDL_Rect r1, SDL_Rect r2)
{
    if(r1.x + r1.w <= r2.x)//r1 esta muy a la i
        return false;

    if(r2.x + r2.w <= r1.x)//r1 esta muy a la der
        return false;

    if(r1.y + r1.h <= r2.y)//r1 esta muy a la i
        return false;

    if(r2.y + r2.h <= r1.y)//r1 esta muy a la der
        return false;

    return true;
}

int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Este es mi mensaje", 100, 100, 800/*WIDTH*/, 600/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //SDL mixer
    if(Mix_OpenAudio(22050, AUDIO_S16, 2, 4096))
    {
        return 40;
    }

    musica = Mix_LoadMUS("musica.ogg");
    Mix_PlayMusic(musica, 1);

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;

    character1 = IMG_LoadTexture(renderer, "derecha1.png");
    character2 = IMG_LoadTexture(renderer, "derecha2.png");
    character3 = IMG_LoadTexture(renderer, "izquierda2.png");
    character4 = IMG_LoadTexture(renderer, "izquierda1.png");
    character5 = IMG_LoadTexture(renderer, "abajo1.png");
    character6 = IMG_LoadTexture(renderer, "abajo2.png");
    character7 = IMG_LoadTexture(renderer, "arriba2.png");
    character8 = IMG_LoadTexture(renderer, "arriba1.png");

    character_otro = IMG_LoadTexture(renderer, "derecha1.png");

    SDL_QueryTexture(character1, NULL, NULL, &w, &h);
    rect_character.x = 0;
    rect_character.y = 0;
    rect_character.w = w;
    rect_character.h = h;

    SDL_QueryTexture(character_otro, NULL, NULL, &w, &h);
    rect_character_otro.x = 40;
    rect_character_otro.y = 50;
    rect_character_otro.w = w;
    rect_character_otro.h = h;

    //Main Loop
    int cont = 0;
    int aux = 0;

 bool a1,a2,a3,a4=false;
a1=true;

    int frame = 0;
    int animacion_personaje = 0;
    int frame_anterior=0;
    Enemigo e(renderer);
    enemigorojo r(renderer);
    enemigonegro we(renderer);
    while(true)
    {
    cout<<SDL_GetTicks()<<endl;

        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {

            }
        }

            const Uint8* estado_teclas=SDL_GetKeyboardState(NULL);

            if(estado_teclas[SDL_SCANCODE_A]){
            a2=true;
                 a1=false;
                 a3=false;
                 a4=false;
                 if(rect_character.x>=0){
                 rect_character.x--;
                 }


                    if(colision(rect_character,rect_character_otro))
                        rect_character.x++;
                }

                 if(estado_teclas[SDL_SCANCODE_S]){
                 a3=true;
                 a2=false;
                 a1=false;
                 a4=false;
                    if(rect_character.y<565)
                    rect_character.y++;



                    if(colision(rect_character,rect_character_otro))
                        rect_character.y--;
                }

                 if(estado_teclas[SDL_SCANCODE_W]){
                 a4=true;
                 a2=false;
                 a3=false;
                 a1=false;
                 if(rect_character.y>=0)
                rect_character.y--;

                    if(colision(rect_character,rect_character_otro))
                        rect_character.y++;
                }
                 if(estado_teclas[SDL_SCANCODE_D]){
                 a1=true;
                 a2=false;
                 a3=false;
                 a4=false;
                 if(rect_character.x<775)
                  rect_character.x++;
                    if(colision(rect_character,rect_character_otro))
                        rect_character.x--;
                }


        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        if(a1==true){

            if(animacion_personaje%2 == 0){

                SDL_RenderCopy(renderer, character1, NULL, &rect_character);
                                          }
            else
                                          {

            SDL_RenderCopy(renderer, character2, NULL, &rect_character);
                                          }
        }
        if(a3==true){

            if(animacion_personaje%2 == 0){

                SDL_RenderCopy(renderer, character5, NULL, &rect_character);
                                          }
            else
                                          {

            SDL_RenderCopy(renderer, character6, NULL, &rect_character);
                                          }
        }
        if(a4==true){

            if(animacion_personaje%2 == 0){

                SDL_RenderCopy(renderer, character7, NULL, &rect_character);
                                          }
            else
                                          {

            SDL_RenderCopy(renderer, character8, NULL, &rect_character);
                                          }
        }
        if(a2==true){

            if(animacion_personaje%2 == 0){

                SDL_RenderCopy(renderer, character3, NULL, &rect_character);
                                          }
            else
                                          {

            SDL_RenderCopy(renderer, character4, NULL, &rect_character);
                                          }
        }


        if(frame%200==0)
        {
            animacion_personaje++;
        }

            e.dibujar();
            e.logica();
            r.dibujar();
            r.logica();
            we.dibujar();
            we.logica();

        SDL_RenderPresent(renderer);
        frame++;
        int frame_actual=SDL_GetTicks()-frame_anterior;
        frame_anterior=SDL_GetTicks();
        if(17-frame_actual>0)
        SDL_Delay(17-frame_actual);

        cout<<frame_actual<<endl;
    }

	return 0;
}
