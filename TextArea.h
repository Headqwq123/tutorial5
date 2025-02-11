#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <string>
#include "RGB.h"       

#include <X11/Xlib.h>

class TextArea {
private:
    int x, y, width, height;
    std::string text;
    // Unique identifier
    std::string id;
    RGB fill;
    RGB border;

public:
    TextArea(int x, int y, int width, int height,
             const std::string& id,
             const std::string& text,
             const RGB& fill = RGB::WHITE(),   
             const RGB& border = RGB::BLACK()); 

    TextArea(const Rectangle& rect,
             const std::string& id,
             const std::string& text,
             const RGB& fill = RGB::WHITE(),
             const RGB& border = RGB::BLACK());

    TextArea();

    TextArea(const TextArea& other);

    // Getters
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    std::string getText() const;
    std::string getId() const;
    RGB getFill() const;
    RGB getBorder() const;

    // Setters
    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);
    void setText(const std::string& text);
    void setId(const std::string& id);
    void setFill(const RGB& fill);
    void setBorder(const RGB& border);

    void draw(Display* display, Window win, GC gc, int offsetX, int offsetY) const;

    bool overlaps(const TextArea& ta) const;

    void print() const;
};

#endif 