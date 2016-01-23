#include "utils.h"
#include "button.h"
#include "pokedex.h"
#include "levelbar.h"
#include "gameengine.h"
#include "Background.h"


using namespace std;

int main(){

    srand (time(NULL));

    //load all variables and objects

    bool menu = true;
   // int clicks = 0;
    sf::Event event;
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Poke Clicker YOYOOYOOOO OOOOOH so gut at dis geim");

//Main environment
    Background background("Resources/Images/background.png");

    //makin buttons, making bacon buttons, taking buttons and then put them in a button, BACON BUTTOOOONS....
    vector<Button*> buttons;

    Button pokeball("Resources/Images/pokeball.png");
    pokeball.setPosition(425,509);
    buttons.push_back(&pokeball);
    pokeball.turnOn();

    Button buyEgg("Resources/Images/buyEgg.png");
    buyEgg.setPosition(643,509);
    buttons.push_back(&buyEgg);

    Button toPokedex("Resources/Images/pokedexbutton.png");
    toPokedex.setPosition(111,509);
    buttons.push_back(&toPokedex);
    toPokedex.turnOn();

    //FEEDEEEERS
    vector<Button*> feeders(3);
    int offset = 333;
    for(uint i = 0; i < feeders.size(); ++i){
        feeders[i] = new Button("Resources/Images/feedButton.png");
        feeders[i]->setPosition(24 + i*offset,275);
        //feeders[i]->turnOn();
    }


//Pokedex environment
    Background pokedexBkg("Resources/Images/pokedexbackground.png");

    Pokedex pokedex("Resources/Images/icons.png",14,11);

    Button back("Resources/Images/backButton.png");
    back.setPosition(881,618);
    back.turnOn();
/*
    LevelBar bar("Resources/Images/lvlbarE.png", "Resources/Images/lvlbarF.png", 941, 24);
*/
     GameEngine gameEngine(window, pokedex);


//game loop
    while(window.isOpen()){

        //handle events
        while(window.pollEvent(event)){
            switch (event.type) {

                //pressed buttons
                case (sf::Event::MouseButtonPressed) :
                case (sf::Event::MouseButtonReleased) :
                    if(menu){
                        for (uint i = 0; i < buttons.size(); ++i){
                            buttons[i]->handleMouseEvent(event);
                        }
                        for (uint i = 0; i < feeders.size(); ++i){
                            feeders[i]->handleMouseEvent(event);
                        }
                    }

                    else back.handleMouseEvent(event);

                    break;

                //closed window
                case (sf::Event::Closed):
                        window.close();
                    break;

            default:
                    break;
            }
        }

    //handle menu scene
        if(menu){

            //update inputs
            for(uint i = 0; i < buttons.size(); ++i){
                buttons[i]->update(sf::Mouse::getPosition(window));
            }

            for(uint i = 0; i < feeders.size(); ++i){
                feeders[i]->update(sf::Mouse::getPosition(window));
            }

            //pokeball button
            gameEngine.update(pokeball.getClicks());

            //feed buttons
            for(uint i = 0; i < feeders.size(); ++i){
                if(gameEngine.canFeed(i)) feeders[i]->turnOn();
            }

            for(uint i = 0; i < feeders.size(); ++i){
                if(feeders[i]->getClicks() > 0){
                    feeders[i]->turnOff();
                    gameEngine.feed(i);
                }
            }

            //buy egg button
            if(gameEngine.canBuy()) buyEgg.turnOn();

            if(buyEgg.getClicks() > 0){
                buyEgg.turnOff();
                gameEngine.requestEgg();
            }

            //switch to pokedex
            if(toPokedex.getClicks() != 0) menu = false;

        //draw all the stuff
            window.clear();
            background.draw(window);
            for (uint i = 0; i < buttons.size(); ++i) window.draw(*buttons[i]);
            for (uint i = 0; i < feeders.size(); ++i) window.draw(*feeders[i]);
            gameEngine.draw();
        }


    //handle pokedex scene
        else{

            //update inputs
            back.update(sf::Mouse::getPosition(window));

            //switch to main
            if(back.getClicks() != 0) menu = true;

            //draw all the stuff
            window.clear();
            pokedexBkg.draw(window);
            pokedex.draw(window);
            window.draw(back);


        }

        window.display();
    }
}
