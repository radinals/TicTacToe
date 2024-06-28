#include "RectF.hpp"
#include "PointF.hpp"
#include "Rect.hpp"
#include <SDL2/SDL_rect.h>

PointF_t
RectF_t::getCenter() const
{
    // FIXME DIV BY ZERO CHECK
    return PointF_t(x + (w / 2.0F), y + (h / 2.0F));
}

PointF_t
RectF_t::getTopLeft() const
{
    return PointF_t(x, y);
}

PointF_t
RectF_t::getTopRight() const
{
    return PointF_t(x + w, y);
}

PointF_t
RectF_t::getBottomLeft() const
{
    return PointF_t(x, y + h);
}

PointF_t
RectF_t::getBottomRight() const
{
    return PointF_t(x + w, y + h);
}
