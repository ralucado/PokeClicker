
#include "gameengine.h"

GameEngine::GameEngine(sf::RenderTarget &window, Pokedex &pokedex) : _window(window), _pokedex(pokedex){
    _totalPokemons = 0;
    _totalClicks = 0;
    _canBuy = false;
    _eggPrice = 250;
    _free = vector<bool>(3, true);
    _canFeed = vector<bool>(3, false);
    _pokemons = vector<Pokemon>(3, Pokemon(-1));
    _eggBar = LevelBar("Resources/Images/eggBarE.png", "Resources/Images/eggBarF.png", 894, 509);


    for(uint i = 0; i < fromEgg.size(); ++i){
        int p = rand()%300;
        _eggs.push(make_pair(fromEgg[i],p));
    }
}

void GameEngine::feed(int num){
    _pokemons[num].addBerry();
    _canFeed[num] = false;
}

bool GameEngine::canBuy(){
    return _canBuy;
}

bool GameEngine::canFeed(int num){
    return _canFeed[num];
}

void GameEngine::requestEgg(){
    int num = _eggs.top().first;
    _eggs.pop();
}

void GameEngine::update(int clicks){
    _totalClicks += clicks;
    cout << _totalClicks << endl;
    for (uint i = 0; i < _pokemons.size(); ++i){
        _pokemons[i].addClicks(clicks);
        if(_pokemons[i].isAdult()){
            _pokedex.addPokemon(_pokemons[i].getNum());
            _emptySlot(i);
        }
    }

}

void GameEngine::draw(){

}

void GameEngine::_emptySlot(int i){
    //...handle sprites
    _canFeed[i] = false;
    _free[i] = true;
}

