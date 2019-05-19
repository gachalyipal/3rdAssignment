#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "graphics.hpp"
#include "widgets.hpp"
#include<vector>

using namespace genv;


class Statictext : public Widget
{
    protected:
        std::string textike;
    public:
        Statictext(int x, int y, int sx, int sy, std::string szoveg);
        virtual void draw();
        virtual void handle(event ev);
        virtual void set_value(std::string _text);
        std::string get_value();
};


#endif
