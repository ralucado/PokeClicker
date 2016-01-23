#ifndef POKEMON_H
#define POKEMON_H

#include "utils.h"
#include "berry.h"

class Pokemon {
public:
    Pokemon(int num);

private:
    bool _isEgg;
    int _num;
    int _targetClicks;
    int _totalEvolutions;
    int _remainingEvolutions;
    vector<Berry> _berries;
};

#endif // POKEMON_H
