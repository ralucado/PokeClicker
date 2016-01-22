#include "utils.h"
#include "button.h"
#include "pokedex.h"
#include "levelbar.h"
#include "gameengine.h"
#include "Background.h"


using namespace std;

int main(){

    //load all variables and objects

    bool menu = true;
   // int clicks = 0;
    sf::Event event;
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Poke Clicker YOYOOYOOOO OOOOOH so gut at dis geim");
    Background background("Resources/Images/background.png");    
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

    Button feed("Resources/Images/feedButton.png");
    feed.setPosition(357,275);
    buttons.push_back(&feed);

    Background pokedexBkg("Resources/Images/pokedexbackground.png");
    Pokedex pokedex("Resources/Images/icons.png",14,11);

    Button back("Resources/Images/backButton.png");
    back.setPosition(881,618);
    back.turnOn();

    GameEngine gameEngine(window);
/*
    LevelBar bar("Resources/Images/lvlbarE.png", "Resources/Images/lvlbarF.png", 941, 24);
    int perc = 0;
*/
    //game loop
    while(window.isOpen()){

        //handle events
        while(window.pollEvent(event)){
            switch (event.type) {

                //pressed buttons
                case (sf::Event::MouseButtonPressed) :
                case (sf::Event::MouseButtonReleased) :
                    if(menu)
                        for (uint i = 0; i < buttons.size(); ++i){
                            buttons[i]->handleMouseEvent(event);
                        }/*
                        for (uint i = 0; i < feeders.size(); ++i){
                            feeders[i]->handleMouseEvent(event);
                        }*/


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

            for(uint i = 0; i < buttons.size(); ++i){
                buttons[i]->update(sf::Mouse::getPosition(window));
            }

            if(toPokedex.getClicks() != 0) menu = false;

            if(pokeball.getClicks() > 0) feed.turnOn();

            if(feed.getClicks() > 0) feed.turnOff();

/*
            if(buyEgg.getClicks() > 0) gameEngine.requestEgg();

/*          perc += pokeball.getClicks();
            bar.update(perc);
*/
            //draw all the stuff
            window.clear();
            background.draw(window);
            for (uint i = 0; i < buttons.size(); ++i) window.draw(*buttons[i]);
            gameEngine.draw();
            //bar.draw(window);
        }


        //handle pokedex scene
        else{

            back.update(sf::Mouse::getPosition(window));
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
