#include "pokemon.h"

Pokemon::Pokemon(){}

Pokemon::Pokemon(int id)
{
    _id = id;
    _isEgg = false;
}

bool Pokemon::isEgg(){
    return _isEgg;
}

void Pokemon::evolve(){
    if(_isEgg) _isEgg = false;
    else ++_id;
}

bool Pokemon::evolves(){
    return EVOLVES[_id];
}

