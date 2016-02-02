#include "pokemon.h"

Pokemon::Pokemon(){}

Pokemon::Pokemon(int id)
{
    _id = id;
    _isEgg = true;
}

bool Pokemon::isEgg(){
    return _isEgg;
}

int Pokemon::getID(){
    return _id;
}

void Pokemon::evolve(){
    if(_isEgg) _isEgg = false;
    else ++_id;
}

bool Pokemon::evolves(){
    return EVOLVES[_id-1];
}

