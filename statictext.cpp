#include "statictext.hpp"
#include "widgets.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace genv;

Statictext::Statictext(int x, int y, int sx, int sy, std::string szoveg) : Widget(x, y, sx, sy)
{
    textike = szoveg;
}

void Statictext::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x,_size_y) << move_to(_x+2,_y+2) << color(0,0,0) << box(_size_x-4,_size_y-4) << move_to(_x+40,_y+25) << color(255,255,255) << text(textike);
}

void Statictext::handle(event ev)
{

}

void Statictext::set_value(std::string _text)
{
    textike = _text;
}

std::string Statictext::get_value()
{
    return textike;
}
