#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <ostream>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
 using namespace std;

#define IMAGE_PATH "Resources/Images/"

namespace State {
    enum myState {released, active, pressed};
}

#endif // UTILS_H
