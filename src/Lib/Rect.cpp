#include "Rect.hpp"
#include "Point.hpp"
#include "RectF.hpp"
#include <SDL2/SDL_rect.h>

Point_t
Rect_t::getCenter() const
{
    // FIXME DIV BY ZERO CHECK
    return Point_t(x + (w / 2.0), y + (h / 2.0));
}

Point_t
Rect_t::getTopLeft() const
{
    return Point_t(x, y);
}

Point_t
Rect_t::getTopRight() const
{
    return Point_t(x + w, y);
}

Point_t
Rect_t::getBottomLeft() const
{
    return Point_t(x, y + h);
}

Point_t
Rect_t::getBottomRight() const
{
    return Point_t(x + w, y + h);
}
