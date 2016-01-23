#ifndef POKEMON_H
#define POKEMON_H

#include "utils.h"
#include "berry.h"

class Pokemon {
public:
    Pokemon(int num);
    bool isAdult();
    void addBerry();
    void addClicks(int clicks);
    int getNum();
private:
    bool _isEgg;
    int _num;
    int _totalClicks;
    int _targetClicks;
    int _totalEvolutions;
    int _remainingEvolutions;
    vector<Berry> _berries;
};

#endif // POKEMON_H
