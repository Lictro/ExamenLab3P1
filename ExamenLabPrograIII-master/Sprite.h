#ifndef SPRITE_H
#define SPRITE_H

#include<SDL.h>
#include<SDL_image.h>

#include <iostream>
#include <vector>
#include "Hitbox.h"
using namespace std;

class Sprite
{
    public:
        int frames;
        vector<Hitbox*>hitboxes;
        SDL_Texture *texture;
        SDL_Rect rect;
        SDL_Renderer* renderer;
        Sprite(SDL_Renderer* renderer,string path,int frames);
        virtual ~Sprite();
        void draw();
    protected:
    private:
};

#endif // SPRITE_H
