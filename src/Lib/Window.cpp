#include "Window.hpp"

#include "Point.hpp"
#include "Rect.hpp"
#include "Size.hpp"
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>

Window_t::Window_t(SDL_Window *window) { m_window = window; }

Window_t::Window_t(const std::string &title,
                   int                x,
                   int                y,
                   int                w,
                   int                h,
                   std::uint32_t      flag)
{
    m_window = SDL_CreateWindow(title.c_str(), x, y, w, h, flag);
}

Window_t::Window_t(const std::string &title,
                   const Rect_t      &rect,
                   std::uint32_t      flag)
{
    m_window
        = SDL_CreateWindow(title.c_str(), rect.x, rect.y, rect.w, rect.h, flag);
}

Window_t::Window_t(const std::string &title,
                   const Point_t     &pos,
                   const Size_t      &size,
                   std::uint32_t      flag)
{
    m_window
        = SDL_CreateWindow(title.c_str(), pos.x, pos.y, size.w, size.h, flag);
}

SDL_Window *
Window_t::getWindow()
{
    return m_window;
}

Rect_t
Window_t::getRect() const
{
    return Rect_t(getPosition().x, getPosition().y, getSize().w, getSize().h);
}

Size_t
Window_t::getSize() const
{
    Size_t size;
    SDL_GetWindowSize(m_window, &size.w, &size.h);
    return size;
}

std::string
Window_t::getTitle() const
{
    return SDL_GetWindowTitle(m_window);
}

Point_t
Window_t::getPosition() const
{
    Point_t pos;
    SDL_GetWindowPosition(m_window, &pos.x, &pos.y);
    return pos;
}

Size_t
Window_t::getMaximumSize() const
{
    Size_t size;
    SDL_GetWindowMaximumSize(m_window, &size.w, &size.h);
    return size;
}

Size_t
Window_t::getMinimumSize() const
{
    Size_t size;
    SDL_GetWindowMinimumSize(m_window, &size.w, &size.h);
    return size;
}

void
Window_t::setMaximumSize(const Size_t &size)
{
    SDL_SetWindowMaximumSize(m_window, size.w, size.h);
}

void
Window_t::setMaximumSize(int w, int h)
{
    SDL_SetWindowMaximumSize(m_window, w, h);
}

void
Window_t::setMinimumSize(const Size_t &size)
{
    SDL_SetWindowMinimumSize(m_window, size.w, size.h);
}

void
Window_t::setMinimumSize(int w, int h)
{
    SDL_SetWindowMinimumSize(m_window, w, h);
}

void
Window_t::setPosition(const Point_t &pos)
{
    SDL_SetWindowPosition(m_window, pos.x, pos.y);
}

void
Window_t::setPosition(int x, int y)
{
    SDL_SetWindowPosition(m_window, x, y);
}

void
Window_t::minimize()
{
    SDL_MinimizeWindow(m_window);
}

void
Window_t::maximize()
{
    SDL_MaximizeWindow(m_window);
}

void
Window_t::raise()
{
    SDL_RaiseWindow(m_window);
}

void
Window_t::bordered(bool bordered)
{
    SDL_SetWindowBordered(m_window, (bordered) ? SDL_TRUE : SDL_FALSE);
}

void
Window_t::grabMouse(bool grab)
{
    SDL_SetWindowMouseGrab(m_window, (grab) ? SDL_TRUE : SDL_FALSE);
}

void
Window_t::resizeable(bool resizeable)
{
    SDL_SetWindowResizable(m_window, (resizeable) ? SDL_TRUE : SDL_FALSE);
}

void
Window_t::setOpacity(float opacity)
{
    SDL_SetWindowOpacity(m_window, opacity);
}
