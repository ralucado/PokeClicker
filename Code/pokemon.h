#ifndef POKEMON_H
#define POKEMON_H

#include "utils.h"

class Pokemon
{
public:
    Pokemon(int id, bool isEgg);
    bool isEgg();
    void hatch();
    bool evolves();

private:
    int id;
    bool _isEgg;

};

#endif // POKEMON_H
