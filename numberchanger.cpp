#include "numberchanger.hpp"
#include <iostream>

using namespace genv;
using namespace std;


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
Numberchanger::Numberchanger(int x, int y, int sx, int sy, int minimum, int maximum, int newnumber) : Widget(x,y, sx, sy)
{
    min = minimum;
    max = maximum;
    number = newnumber;
    basenumber = to_string(number);
}

bool Numberchanger::is_focusable()
{
    return _focused;
}

bool Numberchanger::is_plusbutton(int mouse_x, int mouse_y)
{
    return mouse_x>_x+_size_x-20 && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y/2;
}

bool Numberchanger::is_minusbutton(int mouse_x, int mouse_y)
{
    return mouse_x>_x+_size_x-20 && mouse_x<_x+_size_x && mouse_y>_y+_size_y/2 && mouse_y<_y+_size_y;
}

void Numberchanger::draw()
{
    gout << move_to(_x,_y) << color(255,255,255) << box(_size_x,_size_y) << move_to(_x+2,_y+2) << color(0,0,0) << box(_size_x-4,_size_y-4) << color(255,255,255) << move_to(_x+_size_x/2-20,_y+_size_y/2+5) << text(basenumber);
    gout << move_to(_x+_size_x-22, _y) << color(255,255,255) << box(20, _size_y) << move_to(_x+_size_x-20, _y+2) << color(0,0,0) << box(18, _size_y-4);
    gout << move_to(_x+_size_x-14, _y+_size_y/2-_size_y/10) << color(255,255,255) << text("+");
    gout << move_to(_x+_size_x-14, _y+_size_y/2+3*_size_y/10) << color(255,255,255) << text("-");
}

void Numberchanger::handle(genv::event ev)
{
    if(ev.type == ev_mouse && ev.button == btn_left)
    {
        if(is_plusbutton(ev.pos_x, ev.pos_y)&& number<max)
        {
            number++;
        }
        if(is_minusbutton(ev.pos_x, ev.pos_y) && number>min)
        {
            number--;
        }
    }
    if(ev.type == ev_key && ev.keycode == key_up && number<max)
    {
        number++;
    }
    if(ev.type == ev_key && ev.keycode == key_down && number>min)
    {
        number--;
    }
    if(ev.type == ev_key && ev.keycode == key_pgup && number<max-9)
    {
        number+=10;
    }
    if(ev.type == ev_key && ev.keycode == key_pgdn && number>min+9)
    {
        number-=10;
    }
    if(ev.type == ev_key && ev.keycode == key_home)
    {
        number = 0;
    }

    basenumber = std::to_string(number);
}
string Numberchanger :: value()
{
    return basenumber;
}
