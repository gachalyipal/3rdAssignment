#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "widgets.hpp"
#include <string>
#include <functional>

class Button : public Widget {
protected:
    std::function <void(Button*)> funk;
    std::string str;
    bool _focused;
    bool on_clicked;
    void* parent;
public:
    Button(int x, int y, int sx, int sy, std::string text, void* _parent, std::function <void(Button*)>_funk);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual bool is_focused();
    virtual std::string get_value(){return str;};
    virtual void set_value(std::string _text);
    virtual void set_click();
    virtual bool get_click();
};



#endif // BUTTON_HPP_INCLUDED
