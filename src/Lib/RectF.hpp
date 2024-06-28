#ifndef RECTF_HPP
#define RECTF_HPP

#include <SDL2/SDL_rect.h>

#include "PointF.hpp"

class RectF_t : public SDL_FRect {
public:
    RectF_t() : SDL_FRect { 0, 0, 0, 0 } { }
    RectF_t(float x, float y, float w, float h) : SDL_FRect { x, y, w, h } { }

    PointF_t getCenter() const;
    PointF_t getTopLeft() const;
    PointF_t getTopRight() const;
    PointF_t getBottomLeft() const;
    PointF_t getBottomRight() const;
};

#endif    // !RECTF_HPP
