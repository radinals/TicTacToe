#ifndef RECT_HPP
#define RECT_HPP

#include <SDL2/SDL_rect.h>

#include "Point.hpp"

class Rect_t : public SDL_Rect {
public:
    Rect_t() : SDL_Rect { 0, 0, 0, 0 } { }
    Rect_t(int x, int y, int w, int h) : SDL_Rect { x, y, w, h } { }

    Point_t getCenter() const;
    Point_t getTopLeft() const;
    Point_t getTopRight() const;
    Point_t getBottomLeft() const;
    Point_t getBottomRight() const;
};

#endif    // !RECT_HPP
