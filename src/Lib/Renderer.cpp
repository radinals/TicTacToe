#include "Renderer.hpp"
#include "Color.hpp"
#include "Point.hpp"
#include "PointF.hpp"
#include "Rect.hpp"
#include "RectF.hpp"
#include "Size.hpp"

#include <SDL2/SDL_error.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

Renderer_t::Renderer_t(SDL_Window* window, int index, uint32_t flags)
{
    m_renderer = SDL_CreateRenderer(window, index, flags);
}

Renderer_t::Renderer_t(SDL_Renderer* renderer) { m_renderer = renderer; }

Renderer_t::~Renderer_t() { SDL_DestroyRenderer(m_renderer); }

SDL_Renderer*&
Renderer_t::getRenderer()
{
    return m_renderer;
}

void
Renderer_t::clear()
{
    SDL_RenderClear(m_renderer);
}
void
Renderer_t::present()
{
    SDL_RenderPresent(m_renderer);
}

void
Renderer_t::setColor(int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}

void
Renderer_t::setColor(const Color_t& color)
{
    SDL_SetRenderDrawColor(m_renderer,
                           color.getR(),
                           color.getG(),
                           color.getB(),
                           color.getA());
}

void
Renderer_t::drawLine(const Point_t& source, const Point_t& dest)
{
    SDL_RenderDrawLine(m_renderer, source.x, source.y, dest.x, dest.y);
}

void
Renderer_t::drawLine(const PointF_t& source, const PointF_t& dest)
{
    SDL_RenderDrawLineF(m_renderer, source.x, source.y, dest.x, dest.y);
}

void
Renderer_t::drawLines(const Point_t lines[], int count)
{
    SDL_RenderDrawLines(m_renderer, lines, count);
}

void
Renderer_t::drawLines(const PointF_t lines[], int count)
{
    SDL_RenderDrawLinesF(m_renderer, lines, count);
}

void
Renderer_t::drawPoint(const Point_t& point)
{
    SDL_RenderDrawPoint(m_renderer, point.x, point.y);
}

void
Renderer_t::drawPoint(const PointF_t& point)
{
    SDL_RenderDrawPointF(m_renderer, point.x, point.y);
}

void
Renderer_t::drawPoints(const Point_t points[], int count)
{
    SDL_RenderDrawPoints(m_renderer, points, count);
}

void
Renderer_t::drawPoints(const PointF_t points[], int count)
{
    SDL_RenderDrawPointsF(m_renderer, points, count);
}

void
Renderer_t::drawRect(const Rect_t& rect)
{
    SDL_RenderDrawRect(m_renderer, &rect);
}

void
Renderer_t::drawRect(const RectF_t& rect)
{
    SDL_RenderDrawRectF(m_renderer, &rect);
}

void
Renderer_t::drawRect(const Point_t& pos, const Size_t& size)
{
    Rect_t r(pos.x, pos.y, size.w, size.h);
    SDL_RenderDrawRect(m_renderer, &r);
}

void
Renderer_t::drawRects(const Rect_t rects[], int count)
{
    SDL_RenderDrawRects(m_renderer, rects, count);
}

void
Renderer_t::drawRects(const RectF_t rects[], int count)
{
    SDL_RenderDrawRectsF(m_renderer, rects, count);
}

void
Renderer_t::drawFillRect(const Rect_t& rect)
{
    SDL_RenderFillRect(m_renderer, &rect);
}

void
Renderer_t::drawFillRect(const RectF_t& rect)
{
    SDL_RenderFillRectF(m_renderer, &rect);
}

void
Renderer_t::drawFillRect(const Point_t& pos, const Size_t& size)
{
    Rect_t r(pos.x, pos.y, size.w, size.h);
    SDL_RenderFillRect(m_renderer, &r);
}

void
Renderer_t::drawFillRects(const Rect_t rects[], int count)
{
    SDL_RenderFillRects(m_renderer, rects, count);
}

void
Renderer_t::drawFillRects(const RectF_t rects[], int count)
{
    SDL_RenderFillRectsF(m_renderer, rects, count);
}
