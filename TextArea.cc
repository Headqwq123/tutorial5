#include "TextArea.h"
#include <iostream>
#include <iomanip>
#include <X11/Xlib.h>

TextArea::TextArea(int x, int y, int width, int height,
                   const std::string& id,
                   const std::string& text,
                   const RGB& fill,
                   const RGB& border)
    : x(x), y(y), width(width), height(height),
      id(id), text(text), fill(fill), border(border) {}

TextArea::TextArea(const Rectangle& rect,
                   const std::string& id,
                   const std::string& text,
                   const RGB& fill,
                   const RGB& border)
    : x(rect.x), y(rect.y), width(rect.width), height(rect.height),
      id(id), text(text), fill(fill), border(border) {}

TextArea::TextArea()
    : x(0), y(0), width(50), height(20),
      id("default"), text("default text"),
      fill(RGB::WHITE()), border(RGB::BLACK()) {}

TextArea::TextArea(const TextArea& other)
    : x(other.x), y(other.y), width(other.width), height(other.height),
      id(other.id), text(other.text), fill(other.fill), border(other.border) {}

int TextArea::getX() const { return x; }
int TextArea::getY() const { return y; }
int TextArea::getWidth() const { return width; }
int TextArea::getHeight() const { return height; }
std::string TextArea::getText() const { return text; }
std::string TextArea::getId() const { return id; }
RGB TextArea::getFill() const { return fill; }
RGB TextArea::getBorder() const { return border; }

void TextArea::setX(int x) { this->x = x; }
void TextArea::setY(int y) { this->y = y; }
void TextArea::setWidth(int width) { this->width = width; }
void TextArea::setHeight(int height) { this->height = height; }
void TextArea::setText(const std::string& text) { this->text = text; }
void TextArea::setId(const std::string& id) { this->id = id; }
void TextArea::setFill(const RGB& fill) { this->fill = fill; }
void TextArea::setBorder(const RGB& border) { this->border = border; }

void TextArea::draw(Display* display, Window win, GC gc, int offsetX, int offsetY) const {
    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, x + offsetX, y + offsetY, width, height);

    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, x + offsetX, y + offsetY, width, height);

    Font font = XLoadFont(display, "fixed");
    if (font == BadFont) {
        std::cerr << "Failed to load font 'fixed'. Using default font." << std::endl;
        font = XLoadFont(display, "9x15");
    }
    XSetFont(display, gc, font);
    int textX = x + offsetX + 5;  
    int textY = y + offsetY + 15; 
    XDrawString(display, win, gc, textX, textY, text.c_str(), static_cast<int>(text.size()));

    XUnloadFont(display, font);
}

bool TextArea::overlaps(const TextArea& ta) const {
    return (x < ta.x + ta.getWidth() &&
            x + width > ta.x &&
            y < ta.y + ta.getHeight() &&
            y + height > ta.y);
}

void TextArea::print() const {
    std::cout << "TextArea id: " << id << std::endl;
    std::cout << "Preferred location: " << x << ", " << y << std::endl;
    std::cout << "Size: " << width << " x " << height << std::endl;
    std::cout << "Text: " << text << std::endl;
}
