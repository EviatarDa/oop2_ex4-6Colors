#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>

enum class Colors
{
    Invalid,
    Eval,
    SubStr,
    Add,
    Mul,
    Comp,
    Del,
    Read,
    Resize,
    Help,
    Exit,
};

const int WINDOW_HEIGHT = 800;
const int WINDOW_WIDTH = 1400;
const int ROW = 11;
const int COL = 11;

class Resources
{
public:
    Resources();
    ~Resources() = default;
    static Resources& instance();


private:


};