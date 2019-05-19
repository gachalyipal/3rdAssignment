#include "graphics.hpp"

#include <vector>
#include <iostream>

#include "JatekMester.hpp"

using namespace genv;
using namespace std;




int main()
{
    // A program mûködik nxn-es méretben. Azért inditjuk 30x30-asban hogy kiférjen a monitoromra
    JatekMester amoba(550,500,19);
    amoba.event_loop();
    return 0;
}
