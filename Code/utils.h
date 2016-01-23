#ifndef UTILS_H
#define UTILS_H

#include <queue>
#include <string>
#include <vector>
#include <time.h>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
 using namespace std;

#define uint unsigned int

class Compare
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.second>n2.second;
    }
};

namespace State {
    enum myState {released, active, pressed, off};
}

const int fromEgg[] = {1, 4, 7, 10, 13, 16, 19, 21, 23, 25, 27, 29, 32, 35, 37, 39, 41, 43, 46, 48, 50, 52, 54, 56, 58, 60, 63, 66, 69, 72,
                        74, 77, 79, 81, 83, 84, 86, 88, 90, 92, 95, 96, 98, 100, 102, 104, 106, 108, 109, 111, 113, 114, 115, 116, 118, 120,
                        122, 123, 124, 125, 126, 127, 128, 129, 131, 132, 133, 133, 133, 137, 138, 140, 142, 143, 144, 145, 146, 147, 150, 151};
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
