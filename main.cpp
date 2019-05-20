#include "graphics.hpp"

#include <vector>
#include <iostream>

#include "JatekMester.hpp"

using namespace genv;
using namespace std;


int main()
{
    JatekMester amoba(550,500,18);
    amoba.event_loop();
    return 0;
}
