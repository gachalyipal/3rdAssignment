#include "Button.hpp"
#include <functional>
#include <iostream>

using namespace genv;

Button::Button(int x, int y, int sx, int sy,  std::string text, void* _parent, std::function <void(Button*)>_funk): Widget(x,y,sx,sy),str(text),parent(_parent),funk(_funk)
{
    funk=_funk;
    str=text;
    _focused=false;
    on_clicked=false;
}
void Button::draw()
{

    if (_focused==true)
    {
        gout <<  color(0,255,0);
    }
    else
    {
        gout <<color(255,255,255);
    }

    gout << move_to(_x, _y) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    gout << color(255,255,255)<<move_to(_x+5,_y+_size_y/2+2)<< text(str);
}

void Button::handle(event ev)
{
    if (ev.type == ev_mouse && ev.button==btn_left)
    {
        if ( is_selected(ev.pos_x, ev.pos_y)== true )
        {
 //           on_clicked=true;
            _focused=true;
            funk(this);
        }
        else
        {
            _focused=false;
            on_clicked=false;
        }
    }
}

void Button::set_value(std::string _text)
{
    str = _text;
}

bool Button::is_focused()
{
    return _focused;
}

void Button:: set_click(){
    on_clicked=false;
}

bool Button:: get_click(){
    return on_clicked;
}
