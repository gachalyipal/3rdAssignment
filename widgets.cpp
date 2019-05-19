#include "widgets.hpp"
#include "graphics.hpp"

using namespace genv;

Widget::Widget(int x, int y, int sx, int sy) : _x(x), _y(y), _size_x(sx), _size_y(sy)
{
}

bool Widget::is_selected(int mouse_x, int mouse_y)
{
    if(mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y)
    {
        return true;
    }
    else {return false;}
}

int Widget::get_x()
{
    return _x;
}

int Widget::get_y()
{
    return _y;
}

