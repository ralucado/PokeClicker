#include "pokemon.h"

Pokemon::Pokemon(int id, bool isEgg)
{

}

bool Pokemon::isEgg(){
    return _isEgg;
}

void Pokemon::hatch(){
    _isEgg = false;
}

bool Pokemon::evolves(){
    return EVOLVES[_id];
}
