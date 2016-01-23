#include "pokemon.h"

Pokemon::Pokemon(int num){
    _num = num;
}

int Pokemon::getNum(){
    return _num;
}

bool Pokemon::isAdult(){
    return _targetClicks <= _totalClicks;
}

void Pokemon::addBerry(){

}

void Pokemon::addClicks(int clicks){
    _totalClicks += clicks;
}
