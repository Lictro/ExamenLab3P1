#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <map>
#include "Move.h"
using namespace std;

class Character
{
    public:
        map<string,Move*>moves;
        string current_move;
        int current_sprite;
        int current_sprite_frame;
        Character(SDL_Renderer* renderer);
        virtual ~Character();
        void logic();
        void draw();
        Move* getMove(SDL_Renderer *renderer, string name, int sprite_amount);
    protected:
    private:
};

#endif // CHARACTER_H
