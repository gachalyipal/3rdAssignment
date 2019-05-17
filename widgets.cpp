#include "widgets.hpp"
#include "graphics.hpp"

using namespace genv;

Widget::Widget(int x, int y, int sx, int sy) : _x(x), _y(y), _size_x(sx), _size_y(sy)
{
}

bool Widget::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}

int Widget::get_x()
{
    return _x;
}

int Widget::get_y()
{
    return _y;
}

int Widget::get_size_x()
{
    return _size_x;
}

int Widget::get_size_y()
{
    return _size_y;
}
