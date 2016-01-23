#include "pokemon.h"

Pokemon::Pokemon(int num){
    _num = num;
}

bool Pokemon::isAdult(){
    return _targetClicks <= _totalClicks;
}
