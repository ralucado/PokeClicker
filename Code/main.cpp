#include "utils.h"
#include "button.h"
#include "box.h"
#include "pokedex.h"
#include "levelbar.h"
#include "Background.h"


using namespace std;

int main(){

   //load all variables and objects
    srand (time(NULL));
    sf::Music music;
    if (!music.openFromFile("Resources/Sounds/music.ogg")) cout << "failed to load music" << endl; // error
    music.setLoop(true);
    music.setVolume(25);
    music.play();
    sf::Event event;
    sf::Clock _deltaClock;
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Poke Clicker YOYOOYOOOO OOOOOH so gut at dis geim");
    Background background("Resources/Images/background.png");
    Background pokedexBkg("Resources/Images/pokedexbackground.png");
    Pokedex pokedex("Resources/Images/icons.png",14,11);
    vector<Box*> boxes(3);
    vector<Button*> buttons;
    vector<Button*> feeders(3);
    Button pokeball("Resources/Images/pokeball.png");
    Button buyEgg("Resources/Images/buyEgg.png");
    Button toPokedex("Resources/Images/pokedexbutton.png");
    Button back("Resources/Images/backButton.png");
    LevelBar eggBar("Resources/Images/eggBarE.png", "Resources/Images/eggBarF.png", 894, 509);
    sf::Texture pokemonTexture, shinyTexture, eggTexture;
    priority_queue< pair<int,int>, vector< pair<int,int>>, Compare> eggs;

    for(uint i = 0; i < FROM_EGG.size(); ++i){
         eggs.push(make_pair(FROM_EGG[i],rand()%9999));
    }


//Main environment
    int newClicks;
    bool menu = true;
    bool canBuy = false;
    int eggClicks = 0;
    int berryClicks = 0;
    int eggPrice = 10;
    int freeBox;

    //makin buttons, making bacon buttons, taking buttons and then put them in a button, BACON BUTTOOOONS....

    pokeball.setPosition(425,509);
    buttons.push_back(&pokeball);
    pokeball.turnOn();

    buyEgg.setPosition(643,509);
    buttons.push_back(&buyEgg);

    toPokedex.setPosition(111,509);
    buttons.push_back(&toPokedex);
    toPokedex.turnOn();

    if(!pokemonTexture.loadFromFile("Resources/Images/pokemons.png"))cout << "couldnt load pokemon sprite texture!" << endl;
    if(!shinyTexture.loadFromFile("Resources/Images/shiny.png"))cout << "couldnt load shiny pokemon sprite texture!" << endl;
    if(!eggTexture.loadFromFile("Resources/Images/egg.png")) cout << "couldnt load egg texture!" << endl;

    //SLOTS
    int offset = 333;
    for(uint i = 0; i<3; ++i){
        boxes[i] = new Box(pokemonTexture, shinyTexture, eggTexture, 24 + i*offset, 24);
    }

    //FEEDEEEERS

    for(uint i = 0; i < feeders.size(); ++i){
        feeders[i] = new Button("Resources/Images/feedButton.png");
        feeders[i]->setPosition(24 + i*offset,275);
    }


//Pokedex environment

    back.setPosition(881,618);
    back.turnOn();

//game loop
    while(window.isOpen()){
        //cout << "ekisku te cierras" << endl;

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
            newClicks = pokeball.getClicks();
            if(eggClicks < eggPrice) eggClicks += newClicks;
            //cout << "clicat pokeball " << newClicks << " time/s" << endl;
            bool addClicks = false;
            //feed buttons
            for(uint i = 0; i < feeders.size(); ++i){
                if(!boxes[i]->isFree()){
                    addClicks = true;
                    if(!feeders[i]->isOn()){
                        //cout << "box " << i << " feeder is off, can i turn it on?" << endl;
                        if(boxes[i]->canFeed(berryClicks)) feeders[i]->turnOn();
                    }
                    else if(!boxes[i]->canFeed(berryClicks)){
                         //cout << "box " << i << " feeder is ON. can i turn it off?" << endl;
                        feeders[i]->turnOff();
                    }

                    if(feeders[i]->getClicks() > 0){
                        //cout << "clicat feeder " << i << endl;
                        int price = boxes[i]->buyBerry();
                        //cout << "bought berry for box " << i << " costs " << price << endl;
                        berryClicks -= price;
                        feeders[i]->turnOff();
                    }
                }
                else if(feeders[i]->isOn()) feeders[i]->turnOff();
            }

            if(addClicks && newClicks != 0){
                berryClicks += newClicks;
                //cout << "berryClicks " << berryClicks << endl;
            }
            //slots
            float deltaTime = _deltaClock.getElapsedTime().asSeconds();
            //cout << "main dTime" << deltaTime << endl;
            for (uint i =  0; i < boxes.size(); ++i){
                boxes[i]->update(newClicks, berryClicks, pokedex.size(), deltaTime);
            }
            _deltaClock.restart();

            //buy egg button
            if(!buyEgg.isOn() && canBuy) buyEgg.turnOn();

            if(buyEgg.getClicks() > 0){
                buyEgg.turnOff();
                canBuy = false;
                eggClicks = eggClicks - eggPrice;
                //eggPrice *= 2;
                eggBar.update((eggClicks*100)/eggPrice);

                boxes[freeBox]->addPokemon(eggs.top().first,15);
                eggs.pop();
            }

            //update stuff
            eggBar.update((eggClicks*100)/eggPrice);

            if(!canBuy){
                freeBox = -1;
                for (uint i =  0; i < boxes.size(); ++i){
                    if(boxes[i]->isFree()) freeBox = i;
                }
                if(eggClicks >= eggPrice && freeBox != -1) canBuy = true;
            }

        //switch to pokedex
        if(toPokedex.getClicks() != 0) menu = false;

        //draw all the stuff
            window.clear();
            background.draw(window);
            for (uint i = 0; i < boxes.size(); ++i) boxes[i]->draw(window);
            for (uint i = 0; i < buttons.size(); ++i) window.draw(*buttons[i]);
            for (uint i = 0; i < feeders.size(); ++i) window.draw(*feeders[i]);
            eggBar.draw(window);

            for(uint i = 0; i < boxes.size(); ++i){
                while(!boxes[i]->getStack().empty()){
                    pokedex.addPokemon(boxes[i]->getStack().top());
                    cout << "adding to pokedex ID: " << boxes[i]->getStack().top() << endl;
                    boxes[i]->getStack().pop();
                    eggPrice += (eggPrice/3)*0.05;
                }
            }

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

    for(uint i = 0; i < feeders.size(); ++i){
        delete feeders[i];
    }/*
    for(uint i = 0; i < buttons.size(); ++i){
        delete buttons[i];
    }*/
    for(uint i = 0; i < boxes.size(); ++i){
        delete boxes[i];
    }
}
