#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <cstdint>

#include "Color.hpp"
#include "Point.hpp"
#include "PointF.hpp"
#include "Rect.hpp"
#include "RectF.hpp"
#include "Size.hpp"

#include <SDL2/SDL_error.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

class Renderer_t {
public:
    Renderer_t() { }
    Renderer_t(SDL_Window*, int, uint32_t);
    Renderer_t(SDL_Renderer*);
    ~Renderer_t();

    SDL_Renderer*& getRenderer();

    void clear();
    void present();

    void setColor(int, int, int, int);
    void setColor(const Color_t&);

    void drawLine(const Point_t&, const Point_t&);
    void drawLine(const PointF_t&, const PointF_t&);

    void drawLines(const Point_t[], int count);
    void drawLines(const PointF_t[], int count);

    void drawPoint(const Point_t&);
    void drawPoint(const PointF_t&);

    void drawPoints(const Point_t[], int count);
    void drawPoints(const PointF_t[], int count);

    void drawRect(const Rect_t&);
    void drawRect(const RectF_t&);
    void drawRect(const Point_t&, const Size_t&);

    void drawRects(const Rect_t[], int count);
    void drawRects(const RectF_t[], int count);

    void drawFillRect(const Rect_t&);
    void drawFillRect(const Point_t&, const Size_t&);
    void drawFillRect(const RectF_t&);

    void drawFillRects(const Rect_t[], int count);
    void drawFillRects(const RectF_t[], int count);

private:
    SDL_Renderer* m_renderer = nullptr;
};

#endif    // !RENDERER_HPP
