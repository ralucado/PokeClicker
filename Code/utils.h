#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
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
/*
const bool fromEgg[152] = {true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false,
                           true, false, true, false, true, false, true, false, true, false, true, false, false, true, false, false, true, false, true,
                           false, true, false, true, false, true, false, false, true, false, true, false, true, false, true, false, true, false, true,
                           false, true, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, true,
                           false, false, true, false, true, false, true, false, true, true, false, true, false, true, false, true, false, true, false,
                           false, true, true, false, true, false, true, false, true, false, true, false, true, true, true, true, false, true, false,
                           true, true, true, true, false, true, false, true, false, true, true, true, true, true, true, true, true, false, true, true,
                           true, false, false, false, true, true, false, true, false, true, true, true, true, true, true, false, false, true, true, true };

const bool evolves[152] = {true, true, false, true, true, false, true, true, false, true, true, false, true, true, false, true, true, false, true, false,
                           true, false, true, false, true, false, true, false, true, true, false, true, true, false, true, false, true, false, true, false,
                           true, false, true, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true,
                           true, false, true, true, false, true, true, false, true, true, false, true, false, true, true, false, true, false, true, false, true,
                           false, false, true, false, true, false, true, false, true, false, true, true, false, false, true, false, true, false, true, false,
                           true, false, true, false, false, false, false, true, false, true, false, false, false, false, true, false, true, false, true, false,
                           false, false, false, false, false, false, false, true, false, false, false, true, true, true, false, false, true, false, true, false,
                           false, false, false, false, false, true, true, false, false, false };*/
#endif // UTILS_H
