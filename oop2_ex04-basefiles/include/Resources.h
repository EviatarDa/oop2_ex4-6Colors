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
    Background,
    Back,
    Six_colors
};

enum Owner
{
    Player,
    Computer,
    None,
};

enum Button
{
    Easy,
    Medium,
    Hard,
};

const int WINDOW_HEIGHT = 800;
const int WINDOW_WIDTH = 1400;

const int ROW = 10;//31; //גובה (מספר שורה)
const int COL = 10;//;54; //רוחב מספר עמודה
const int RADIUS = 15;
const int OUTLINE = 2;


const float HEX_WIDTH = RADIUS * std::sqrt(3.f) + (2*OUTLINE);
const float HEX_HEIGHT = 2.f * RADIUS + (2 * OUTLINE);
const float HEX_EDGH = 2 * RADIUS * sin(3.14159 / 3);

const float GRID_WIDTH = HEX_WIDTH * COL;
const float GRID_HEGHT = ROW * (HEX_HEIGHT * 3.f / 4.f);


const int TEXTURES = 4;
const int BUTTONS = 3;

class Resources
{
public:
    Resources();
    ~Resources() = default;
    static Resources& instance();

    sf::Color* getColorArray();
    sf::Texture& getTexture(Textures);
    sf::Texture& getButton(Button);


private:
    sf::Color m_colorArray[6] = { sf::Color::Cyan, sf::Color::Blue, sf::Color::Green,
        sf::Color::Red, sf::Color::Yellow, sf::Color::Color(255, 119, 0) };

    sf::Texture m_textures[TEXTURES];
    sf::Texture m_Buttons[BUTTONS];

    void LoadFromFile();

};