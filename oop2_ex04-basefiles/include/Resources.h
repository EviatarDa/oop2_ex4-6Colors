#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>


enum Colors
{
    Cyan,
    Blue,
    Green,
    Red,
    Yellow,
    Orange,
};

enum Textures
{
    X_texture,
};

const int WINDOW_HEIGHT = 800;
const int WINDOW_WIDTH = 1400;
const int ROW = 70; //רוחב
const int COL = 46; //גובה
const int RADIUS = 10;
const int OUTLINE = 2;
const int TEXTURES = 1;

class Resources
{
public:
    Resources();
    ~Resources() = default;
    static Resources& instance();

    sf::Color* getColorArray();
    sf::Texture& getTexture(Textures);


private:
    sf::Color m_colorArray[6] = { sf::Color::Cyan, sf::Color::Blue, sf::Color::Green,
        sf::Color::Red, sf::Color::Yellow, sf::Color::Color(255, 119, 0) };

    sf::Texture m_textures[TEXTURES];

};