#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

class Widget {
protected:
    int _x, _y, _size_x, _size_y;
public:
    Widget(int x, int y, int sx, int sy);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual int get_x();
    virtual int get_y();
    virtual int get_size_x();
    virtual int get_size_y();
    virtual std::string value(){};

};

#endif // WIDGETS_HPP_INCLUDED
