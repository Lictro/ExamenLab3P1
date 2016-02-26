#include "Character.h"
int pau=0;
std::string toString(int number)
{
    if (number == 0)
        return "0";

    if(number < 0)
        return "-"+toString(-number);

    std::string temp="";
    std::string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<(int)temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}

Character::Character(SDL_Renderer* renderer)
{
    moves["idle"]=getMove(renderer,"idle",4);
    moves["kick"]=getMove(renderer,"kick",6);
    moves["punch"]=getMove(renderer,"punch",3);
    moves["walk"]=getMove(renderer,"walk",5);

    this->current_move = "idle";
    this->current_sprite = 0;
    this->current_sprite_frame = 0;
}

Move* Character::getMove(SDL_Renderer *renderer, string name, int sprite_amount)
{
    vector<Sprite*>sprites;
    for(int i=1;i<=sprite_amount;i++)
    {
        string path="assets/" + name + "/" + toString(i) + ".png";
        sprites.push_back(new Sprite(renderer,path,10));
    }
    return new Move(renderer,sprites);
}

Character::~Character()
{
    //dtor
}

void Character::logic()
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if( currentKeyStates[ SDL_SCANCODE_V ] )
    {
        pau=1;
    }

if( currentKeyStates[ SDL_SCANCODE_B ] )
    {
        pau=0;
    }
    if(pau==0){
    if( currentKeyStates[ SDL_SCANCODE_Q ] )
    {
        this->current_move = "idle";
        this->current_sprite = 0;
    }
    if( currentKeyStates[ SDL_SCANCODE_W ] )
    {
        this->current_move = "kick";
        this->current_sprite = 0;
    }
    if( currentKeyStates[ SDL_SCANCODE_E ] )
    {
        this->current_move = "punch";
        this->current_sprite = 0;
    }
    if( currentKeyStates[ SDL_SCANCODE_R ] )
    {
        this->current_move = "walk";
        this->current_sprite = 0;
    }

    current_sprite_frame++;
    if(current_sprite_frame>=moves[current_move]->sprites[current_sprite]->frames)
    {
        current_sprite++;
        if(current_sprite>=moves[current_move]->sprites.size())
        {
            current_move= "idle";
            current_sprite=0;
        }
        current_sprite_frame=0;
    }
    }
}

void Character::draw()
{
    moves[current_move]->draw(current_sprite);
}
