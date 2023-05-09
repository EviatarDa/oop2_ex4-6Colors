#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>


enum class Colors
{
    Cyan,
    Blue,
    Green,
    Red,
    Yellow,
};

const int WINDOW_HEIGHT = 800;
const int WINDOW_WIDTH = 1400;
const int ROW = 70; //רוחב
const int COL = 46; //גובה
const int RADIUS = 10;
const int OUTLINE = 2;

class Resources
{
public:
    Resources();
    ~Resources() = default;
    static Resources& instance();

    sf::Color* getColorArray();


private:
    sf::Color m_colorArray[5] = { sf::Color::Cyan, sf::Color::Blue, sf::Color::Green,
        sf::Color::Red, sf::Color::Yellow };
};