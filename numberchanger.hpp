#ifndef NUMBERCHANGER_HPP_INCLUDED
#define NUMBERCHANGER_HPP_INCLUDED
#include "widgets.hpp"

#include "graphics.hpp"
#include "widgets.hpp"
#include "numberchanger.hpp"
#include "select.hpp"
#include "app.hpp"
#include <vector>
#include <iostream>
#include <time.h>


using namespace genv;
using namespace std;
class Numberchanger : public Widget
{
protected:
    bool _focused;
    int min;
    int max;

    std::string basenumber;
public:
    Numberchanger(int x, int y, int sx, int sy, int minimum, int maximum, int basenumber);
    virtual bool is_focusable();
    virtual bool is_plusbutton(int mouse_x, int mouse_y);
    virtual bool is_minusbutton(int mouse_x, int mouse_y);
    virtual void draw ();
    virtual void handle(genv::event ev);
    int number;
    string value();
};

#endif // NUMBERCHANGER_HPP_INCLUDED

