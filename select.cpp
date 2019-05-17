#include "select.hpp"
#include <iostream>
#include <time.h>

using namespace genv;
using namespace std;


Select::Select(int x, int y, int sx, int sy, int ls, int vector_size) : Widget(x,y,sx,sy)
{
    list_size=ls;
    vector_siz = vector_size;

    srand(time(NULL));
    for(int i=0; i<vector_size; i++)
    {
        items.push_back(to_string(rand()%100));
    }

}

bool Select::is_focusable()
{
    return _focused;
}

bool Select::list_expand(int mouse_x, int mouse_y)
{
    return mouse_x>_x+_size_x-20 && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}

void Select::draw()
{
    if(list_open == true)
    {
        disp_items = _y + _size_y;

        if(items.size() < list_size)
            for(size_t i=0; i<items.size(); i++)
            {
                gout<<move_to(_x, disp_items)<<color(255,255,255)<<box(_size_x-20, _size_y);

                if(i == selected)
                {
                    gout<<move_to(_x, disp_items)<<color(0,0,255)<<box(_size_x-24, _size_y-4);
                }
                else
                {
                    gout<<move_to(_x, disp_items)<<color(0,0,0)<<box(_size_x-24, _size_y-4);
                }

                gout<<move_to(_x+10, disp_items+20)<<color(255,255,255)<<text(items[i+item_id]);

            }
            else
            {
                for(size_t i=0; i<list_size; i++)
                {
                    gout<<move_to(_x, disp_items)<<color(255,255,255)<<box(_size_x-20, _size_y);

                    if(i==selected)
                    {
                        gout<<move_to(_x+2, disp_items+2)<<color(0,0,255)<<box(_size_x-24, _size_y-4);
                    }
                    else
                    {
                        gout<<move_to(_x+2, disp_items+2)<<color(0,0,0)<<box(_size_x-24, _size_y-4);
                    }
                    if(items.size()!=0)
                    {
                        gout<<move_to(_x+10, disp_items+20)<<color(255,255,255)<<text(items[i+item_id]);
                    }
                    disp_items+=28;
                }
            }
        }

    else
    {
        gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
        disp_items =_y+_size_y;
        for(size_t i=0; i<list_size; i++)
        {
            gout<<move_to(_x, disp_items)<<color(0,0,0)<<box(_size_x-20, _size_y);
            disp_items+=28;
        }
    }

    gout<<move_to(_x+10, _y+20)<<color(255,255,255)<<text(items[select]);
    gout << move_to(_x+_size_x-20, _y) << color(255,255,255) << box(28, _size_y);
    gout << move_to(_x+_size_x-18, _y+2) << color(0,0,0) << box(24, _size_y-4);
    gout<<move_to(_x+_size_x-10, _y+20)<<color(255,255,255)<<text("V");
}

void Select::handle(event ev)
{
    if (ev.type == ev_mouse && ev.button == btn_wheelup && item_id >0)
    {
        item_id--;
    }
    if (item_id+list_size < items.size() && ev.type == ev_mouse && ev.button == btn_wheeldown)
    {
        item_id++;
    }
    if (ev.type == ev_mouse && list_open == true)
    {
        for(int i=0; i<list_size; i++)
        {
            if(ev.pos_x>_x && ev.pos_x<_x+_size_x-20 && ev.pos_y>_y+_size_y+i*28 && ev.pos_y<_y+_size_y+25+i*28)
            {
                selected = i;
            }
        }
    }

    if (ev.type == ev_mouse && ev.button == btn_left)
    {
        if(list_open == true)
        {
            for(int i=0; i<list_size; i++)
            {
                if( ev.pos_x>_x && ev.pos_x<_x+_size_x-20 && ev.pos_y>_y+_size_y+i*25 && ev.pos_y<_y+_size_y+25+i*25)
                {
                    select=i+item_id;
                }
            }
        }

        if(list_expand(ev.pos_x, ev.pos_y))
        {
            list_open = true;
        }
        else
        {
            list_open = false;
        }

        if (is_selected(ev.pos_x, ev.pos_y) == true)
        {
            _focused = true;
        }
        else
        {
            _focused = false;
        }
    }
}

string Select::value()
{
    return items[select];
}

