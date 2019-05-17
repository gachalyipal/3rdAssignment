#ifndef APP_HPP
#define APP_HPP

#include "widgets.hpp"
#include <vector>
#include <string>

class Application
{
public:
    Application();
    virtual ~Application();
    void event_loop();
    void registerWidget(Widget *w)
    {
        widgets.push_back(w);
    }
    virtual void action(std::string id){};

protected:
   std:: vector<Widget*> widgets;
};

#endif
