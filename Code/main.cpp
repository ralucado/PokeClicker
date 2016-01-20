#include "utils.h"
#include "Background.h"
#include "button.h"

using namespace std;

int main(){
    bool menu = true;
    sf::Event event;
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Poke Clicker YOYOOYOOOO OOOOOH so gut at dis geim");
    Background background("Resources/Images/background.png");    
    vector<Button*> buttons;

    Button pokeball("Resources/Images/pokeball.png");
    pokeball.setPosition(425,509);
    buttons.push_back(&pokeball);

    Button buyegg("Resources/Images/buyegg.png");
    buyegg.setPosition(643,509);
    buttons.push_back(&buyegg);


    Button pokedex("Resources/Images/pokedexbutton.png");
    pokedex.setPosition(111,509);
    buttons.push_back(&pokedex);

    Background pokedexBkg("Resources/Images/pokedexbackground.png");

    Button back("Resources/Images/backButton.png");
    back.setPosition(881,618);

    while(window.isOpen()){


        while(window.pollEvent(event)){

            switch (event.type) {

                case (sf::Event::MouseButtonPressed) :
                case (sf::Event::MouseButtonReleased) :
                    if(menu)
                        for (int i = 0; i < buttons.size(); ++i){
                            buttons[i]->handleMouseEvent(event);
                        }

                    else back.handleMouseEvent(event);

                    break;

                case (sf::Event::Closed):
                        window.close();
                    break;

            default:
                    break;
            }
        }

        if(menu){

            for(int i = 0; i < buttons.size(); ++i){
                buttons[i]->update(sf::Mouse::getPosition(window));
            }

            if(pokedex.getClicks() != 0) menu = false;
            window.clear();
            background.draw(window);
            for (int i = 0; i < buttons.size(); ++i) window.draw(*buttons[i]);
        }

        else{
            //cout << "fora del menu" << endl;
            back.update(sf::Mouse::getPosition(window));
            if(back.getClicks() != 0) menu = true;

            window.clear();
            pokedexBkg.draw(window);
            window.draw(back);


        }


        window.display();

    }
}
