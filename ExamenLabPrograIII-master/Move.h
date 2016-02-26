#ifndef MOVE_H
#define MOVE_H

#include<SDL.h>
#include<SDL_image.h>

#include <iostream>
#include <vector>
#include "Sprite.h"
using namespace std;

class Move
{
    public:
        vector<Sprite*> sprites;
        SDL_Renderer* renderer;
        Move(SDL_Renderer* renderer,vector<Sprite*>sprites);
        int frame;
        int current_sprite_frame;
        virtual ~Move();
        void draw(int current_sprite);
    protected:
    private:
};

#endif // MOVE_H
