#include "utils.h"
#include "Background.h"
#include "button.h"

using namespace std;

int main(){
    sf::Event event;
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Poke Clicker YOYOOYOOOO OOOOOH so gut at dis geim");
    Background background("Resources/Images/background.png");

    vector<Button> buttons;

    Button pokeball("Resources/Images/pokeball.png");
    pokeball.setPosition(425,509);
    buttons.push_back(pokeball);

    Button buyegg("Resources/Images/buyegg.png");
    buyegg.setPosition(643,509);
    buttons.push_back(buyegg);


    Button pokedex("Resources/Images/pokedexbutton.png");
    pokedex.setPosition(111,509);
    buttons.push_back(pokedex);


    while(window.isOpen()){


        for(auto&& b : buttons){
            //cout << b.getClicks() << endl;
            b.update(sf::Mouse::getPosition(window));
        }

        while(window.pollEvent(event)){

            switch (event.type) {

                case (sf::Event::MouseButtonPressed) :
                case (sf::Event::MouseButtonReleased) :

                    for (auto&& b : buttons){
                        b.handleMouseEvent(event);
                    }

                    break;

                case (sf::Event::Closed):
                        window.close();
                    break;

            default:
                    break;
            }
        }

        window.clear();
        background.draw(window);
        for (auto&& b : buttons) window.draw(b);
        window.display();

    }
}
