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

    //fkin eevee
    else if(_id == 133){
        if (!Eevee::VAPOREON){
            ++_id;
            Eevee::VAPOREON = true;
        }
        else if (!Eevee::JOLTEON){
            ++_id; ++_id;
            Eevee::JOLTEON = true;
        }
        else if (!Eevee::FLAREON){
            ++_id; ++_id; ++_id;
            Eevee::FLAREON = true;
        }
    }


    else ++_id;
}

bool Pokemon::evolves(){
    return EVOLVES[_id-1];
}

