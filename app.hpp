#ifndef APP_HPP
#define APP_HPP

#include "widgets.hpp"
#include <vector>
#include <string>

class Application
{
protected:
   std:: vector<Widget*> widgets;
   unsigned int size_x, size_y;
   unsigned int m_x, m_y;
   int focus;
public:
    Application(unsigned int _size_x, unsigned int _size_y);
    virtual ~Application();
    void event_loop();
    void registerWidget(Widget *w)
    {
        widgets.push_back(w);
    };
};

#endif
