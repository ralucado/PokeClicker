
#include "gameengine.h"

GameEngine::GameEngine(sf::RenderTarget &window, Pokedex &pokedex) : _window(window), _pokedex(pokedex){
    _canFeed = vector<bool>(3, false);
    _canBuy = false;
    _totalClicks = 0;
    _numPokemons = 0;
}

void GameEngine::feed(int num){
    _canFeed[num] = false;
}

bool GameEngine::canBuy(){
    return _canBuy;
}

bool GameEngine::canFeed(int num){
    return _canFeed[num];
}

void GameEngine::requestEgg(){

}

void GameEngine::update(int clicks){
    _totalClicks += clicks;
    cout << _totalClicks << endl;
}

void GameEngine::draw(){

}

