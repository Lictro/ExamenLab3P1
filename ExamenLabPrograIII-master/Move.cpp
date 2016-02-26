#include "Move.h"

Move::Move(SDL_Renderer* renderer,vector<Sprite*>sprites)
{
    this->renderer=renderer;
    for(int i=0;i<sprites.size();i++)
    {
        this->sprites.push_back(sprites[i]);
    }
    frame=0;
    current_sprite_frame=0;
}

Move::~Move()
{
    //dtor
}

void Move::draw(int current_sprite)
{
    Sprite* sprite = sprites[current_sprite];
    sprite->draw();
    frame++;
}
