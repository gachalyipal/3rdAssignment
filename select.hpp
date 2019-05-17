#ifndef SELECT_HPP_INCLUDED
#define SELECT_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "numberchanger.hpp"
#include "select.hpp"
#include "app.hpp"
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;
using namespace genv;

/*
class Select : public Widget
{
protected:
    vector<string> sList;

public:

};
*/

class Select : public Widget
{
protected:
    vector<string> items;
    bool list_open = false;
    bool _focused = false;
    int disp_items = 0;
    int list_size = 0;
    int select = 0;
    int item_id = 0;
    int selected = 0;
    int vector_siz = 0;
public:
    Select(int x, int y, int sx, int sy, int ls, int vector_size);
    virtual bool is_focusable();
    virtual bool list_expand(int mouse_x, int mouse_y);
    virtual void draw();
    virtual void handle(genv::event ev);
    string value();
};



#endif // SELECT_HPP_INCLUDED
