#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* renderer, string path, int frames)
{
    this->renderer = renderer;
    texture = IMG_LoadTexture(renderer,path.c_str());
    int w,h;
    SDL_QueryTexture(texture,NULL,NULL,&w,&h);
    rect.w=w;
    rect.h=h;
    rect.x=0;
    rect.y=0;
    this->frames = frames;
}

Sprite::~Sprite()
{
    //dtor
}

void Sprite::draw()
{
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}


