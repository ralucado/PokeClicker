#ifndef POKEMON_H
#define POKEMON_H

#include "utils.h"

class Pokemon
{
public:
    Pokemon();
    Pokemon(int id);
    bool isEgg();
    int getID();
    void evolve();
    bool evolves();
    bool isShiny();

private:
    int _id;
    bool _isEgg;
    bool _shiny;

};

#endif // POKEMON_H
