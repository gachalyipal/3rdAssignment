#include "JatekMester.hpp"
#include "Button.hpp"
#include "statictext.hpp"
#include <iostream>

using namespace std;
using namespace genv;


void JatekMester::logic(unsigned int x, unsigned int y, Button* setbutton)
{
    while(win==false)
    {
        std::string player = "";
        if(is_X == true && setbutton->get_value()=="")
        {
            setbutton->set_value("x");
            is_X = false;
            nextplayer->set_value("Next is player: O");
            player = "x";
        }
        else if(setbutton->get_value()=="")
        {
            setbutton->set_value("o");
            is_X = true;
            nextplayer->set_value("Next is player: X");
            player = "o";
        }
        else
        {
            return;
        }

        vector<Button*> temp_columns;
        vector<Button*> temp_rows;
        vector<Button*> diag1;
        vector<Button*> diag2;
        vector<Button*> diag3;
        vector<Button*> diag4;

        for(unsigned int i=0;i<mapsize;i++)
        {
            for(unsigned int j=0;j<mapsize;j++)
            {
                if(((Button*)widgets[i*mapsize+j])->get_value() == player)
                {
                    temp_columns.push_back((Button*)widgets[i*mapsize+j]);
                    if(temp_columns.size() >= winner){win = true;}
                    if(j == mapsize-1)
                    {
                        if(temp_columns.size() >= winner)columns.push_back(temp_columns);
                        temp_columns.clear();
                    }
                }
                else
                {
                    if(temp_columns.size() >= winner)columns.push_back(temp_columns);
                    temp_columns.clear();
                }

                if(((Button*)widgets[j*mapsize+i])->get_value() == player)
                {
                    temp_rows.push_back(((Button*)widgets[j*mapsize+i]));
                    if(temp_rows.size() >= winner){win = true;}
                    if(j == mapsize-1)
                    {
                        if(temp_rows.size() >= winner)rows.push_back(temp_rows);
                        temp_rows.clear();
                    }
                }
                else
                {
                    if(temp_rows.size() >= winner)rows.push_back(temp_rows);
                    temp_rows.clear();
                }

                if(i+j < mapsize)
                {

                    if(((Button*)widgets[i*mapsize+j*mapsize+j])->get_value() == player)
                    {
                        diag1.push_back(((Button*)widgets[i*mapsize+j*mapsize+j]));
                        if(diag1.size() >= winner){win = true;}
                        if(i+j == mapsize-1)
                        {
                            if(diag1.size() >= winner)diagonal01.push_back(diag1);
                            diag1.clear();
                        }
                    }
                    else
                    {
                        if(diag1.size() >= winner)diagonal01.push_back(diag1);
                        diag1.clear();
                    }
                    if(i > 0)
                    {
                        if(((Button*)widgets[i+j*mapsize+j])->get_value() == player)
                        {
                            diag2.push_back(((Button*)widgets[i+j*mapsize+j]));
                            if(diag2.size() >= winner){win = true;}
                            if(i+j == mapsize-1)
                            {
                                if(diag2.size() >= winner)diagonal01.push_back(diag2);
                                diag2.clear();
                            }
                        }
                        else
                        {
                            if(diag2.size() >= winner)diagonal01.push_back(diag2);
                            diag2.clear();
                        }
                    }

                    if(((Button*)widgets[(mapsize-1-i)+j*mapsize-j])->get_value() == player)
                    {
                        diag3.push_back(((Button*)widgets[(mapsize-1-i)+j*mapsize-j]));
                        if(diag3.size() >= winner){win = true;}
                        if(i+j == mapsize-1)
                        {
                            if(diag3.size() >= winner)diagonal02.push_back(diag3);
                            diag3.clear();
                        }
                    }
                    else
                    {
                        if(diag3.size() >= winner)diagonal02.push_back(diag3);
                        diag3.clear();
                    }
                    if(i > 0)
                    {
                        if(((Button*)widgets[(mapsize-1)+i*mapsize+j*mapsize-j])->get_value() == player)
                        {
                            diag4.push_back(((Button*)widgets[(mapsize-1)+i*mapsize+j*mapsize-j]));
                            if(diag4.size() >= winner){win = true;}
                            if(i+j == mapsize-1)
                            {
                                if(diag4.size() >= winner)diagonal02.push_back(diag4);
                                diag4.clear();
                            }
                        }
                        else
                        {
                            if(diag4.size() >= winner)diagonal02.push_back(diag4);
                            diag4.clear();
                        }
                    }

                }

                if(win == true)break;
            }

            if(win == true)
            {
                nextplayer->set_value("Player "+player+" has won!");
                break;
            }
        }

        unsigned int free_space = 0;
        for(unsigned int i=0;i<mapsize*mapsize;i++)
        {
            if(((Button*)widgets[i])->get_value()=="")
            {
                free_space++;
            }
        }
        if(free_space == 0)
        {
            nextplayer->set_value("It's a Draw");
            return;
        }

    }
}

JatekMester::JatekMester(unsigned int _size_x, unsigned int _size_y, unsigned int _mapsize):Application(_size_x, _size_y)
{
    mapsize = _mapsize;

    for(unsigned int i=0;i < mapsize;i++)
    {
        for(unsigned int j=0;j < mapsize;j++)
        {
            registerWidget(new Button(50+i*20,70+j*20,20,20,"",this,[i,j,this](Button* but)
            {
                logic(i,j,but);
            }
                ));

        }
    }

    nextplayer = new Statictext(140,10,270,40,"First player is: X");
    registerWidget(nextplayer);

    newgame = new Button(50,10,80,40,"New game",this,[&](Button* but)
    {
        for(unsigned int i=0; i< mapsize*mapsize; i++)
        {
            ((Button*)widgets[i])->set_value("");

        }
        nextplayer->set_value("First player is: X");
        win=false;
        is_X=true;

    });
    registerWidget(newgame);

};
