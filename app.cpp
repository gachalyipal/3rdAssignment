#include "app.hpp"
#include <iostream>
#include <fstream>
using namespace genv;
using namespace std;

Application::Application(unsigned int _size_x, unsigned int _size_y):size_x(_size_x), size_y(_size_y)
{
    focus = -1;
    m_x=0;
    m_y=0;
}

Application::~Application()
{

}


void Application :: event_loop()
{
    gout.open(450,450);
    event ev;

    while(gin >> ev && ev.keycode != key_escape )
    {

        if (ev.type == ev_mouse && ev.button==btn_left)
        {
            for (size_t i=0;i<widgets.size();i++)
            {
                if(widgets[i]->is_selected(ev.pos_x, ev.pos_y)==true)
                {
                        focus = i;
                }
            }
        }

        if (focus!=-1)
        {
            widgets[focus]->handle(ev);
        }

        if(ev.type == ev_mouse)
        {
            m_x = ev.pos_x;
            m_y = ev.pos_y;
        }
        else
        {
            ev.pos_x = m_x;
            ev.pos_y = m_y;
        }

        for (Widget * w : widgets)
        {
            w->draw();
        }
        gout << refresh;
        }
}

