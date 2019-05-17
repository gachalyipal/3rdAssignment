#include "app.hpp"
#include <iostream>
#include <fstream>
using namespace genv;
using namespace std;

Application::Application()
{

}

Application::~Application()
{

}


void Application :: event_loop()
{
    event ev;
    int focus = -1;

    while(gin >> ev && ev.keycode != key_escape )
    {
        if (ev.keycode == key_enter)
        {
            ofstream of("outputFile.txt");
            for(int i=0; i<widgets.size();i++)
            {
                of << widgets[i]->value() << endl;
            }
            of.close();
        }

        if (ev.type == ev_mouse && ev.button==btn_left)
        {
            for (size_t i=0;i<widgets.size();i++)
            {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                        focus = i;
                }
            }
        }

        if (focus!=-1)
        {
            widgets[focus]->handle(ev);
        }

        for (Widget * w : widgets)
        {
            w->draw();
        }
        gout << refresh;
        }
}

