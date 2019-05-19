#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "widgets.hpp"
#include <string>
#include <functional>
using namespace std;

class Button : public Widget {
protected:
    function <void(Button*)> funk;
    string str;
    bool _focused;
    bool on_clicked;
    void* parent;
public:
    Button(int x, int y, int sx, int sy, string text, void* _parent, function <void(Button*)>_funk);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual bool is_focused();
    virtual string get_value(){return str;};
    virtual void set_value(std::string _text);
    virtual void set_click();
    virtual bool get_click();
};



#endif // BUTTON_HPP_INCLUDED
