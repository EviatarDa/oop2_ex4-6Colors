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
};

enum Owner
{
    Player,
    Computer,
    None,
};

enum Button
{
    Eazy,
    Medium,
    Hard,
};

const int WINDOW_HEIGHT = 800;
const int WINDOW_WIDTH = 1400;

const int ROW = 31; //���� (���� ����)
const int COL = 54; //���� ���� �����
const int RADIUS = 15;

const float HEX_WIDTH = RADIUS * std::sqrt(3.f);
const float HEX_HEIGHT = 2.f * RADIUS;

const int OUTLINE = 2;
const int TEXTURES = 2;
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