#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED

#include "app.hpp"
#include "button.hpp"
#include "statictext.hpp"

class JatekMester : public Application
{
protected:
    bool is_X = true;
    bool win = false;
    unsigned int mapsize;
    unsigned int winner = 5;
    std::vector<std::vector<Button*>> columns;
    std::vector<std::vector<Button*>> rows;
    std::vector<std::vector<Button*>> diagonal01;
    std::vector<std::vector<Button*>> diagonal02;
    Button* newgame;
    Statictext* nextplayer;
public:
    JatekMester(unsigned int _size_x, unsigned int _size_y, unsigned int n);
    void logic(unsigned int x, unsigned int y, Button* setbutton);
};


#endif // JATEKMESTER_HPP_INCLUDED
