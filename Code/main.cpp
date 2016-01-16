#include "utils.h"
#include "Background.h"
#include "button.h"

using namespace std;

int main(){
  sf::Event event;
  sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Poke Clicker YOYOOYOOOO OOOOOH so gut at dis geim");
  //string path = "background.png";
  //string path2 = IMAGE_PATH + "2";
  Background background("Resources/Images/background.png");

  vector<Button> buttons;
  Button pokeball("Resources/Images/pokeball.png");
  pokeball.setPosition(425,509);
  buttons.push_back(pokeball);

  while(window.isOpen()){

    while(window.pollEvent(event)){

        for (auto b : buttons){
            b.handleEvent(event);
        }
        switch (event.type) {

        case (sf::Event::Closed):
                window.close();
            break;
                default:
            break;
        }
    }

      window.clear();
      background.draw(window);
//      window.draw();
    window.display();

  }
}
