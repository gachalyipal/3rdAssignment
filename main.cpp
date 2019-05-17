#include "graphics.hpp"
#include "widgets.hpp"
#include "numberchanger.hpp"
#include "select.hpp"
#include "app.hpp"
#include <vector>
#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;
using namespace genv;

class MyApplication : public Application
{
public:
    MyApplication()
    {
        Numberchanger * nc1 = new Numberchanger(20, 80, 120, 40, -1000, 1000, 0);
        Numberchanger * nc2 = new Numberchanger(20, 216, 120, 40, -100, 100, 0);
        Select * s1 = new Select(220,84,120,30,3,10);
        Select * s2 = new Select(220,220,120,30,5,20);

        registerWidget(nc1);
        registerWidget(nc2);
        registerWidget(s1);
        registerWidget(s2);



    }

protected:
    Numberchanger * nc1;
    Numberchanger * nc2;
    Select * s1;
    Select * s2;
};

int main()
{
    gout.open(400,400);
    vector<Widget*> w;

    for (Widget * wg : w) {
        wg->draw();
    }

    MyApplication app;
    app.event_loop();
    return 0;
}
