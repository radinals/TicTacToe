#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "Point.hpp"
#include "Rect.hpp"
#include "Size.hpp"

#include <SDL2/SDL_video.h>
#include <cstdint>
#include <string>

class Window_t {
public:
    Window_t() { }
    Window_t(SDL_Window *);
    Window_t(const std::string &, int, int, int, int, std::uint32_t);
    Window_t(const std::string &, const Rect_t &, std::uint32_t);
    Window_t(const std::string &,
             const Point_t &,
             const Size_t &,
             std::uint32_t);

    SDL_Window *getWindow();

    Rect_t      getRect() const;
    Size_t      getSize() const;
    std::string getTitle() const;
    Point_t     getPosition() const;
    Size_t      getMaximumSize() const;
    Size_t      getMinimumSize() const;

    void setMaximumSize(const Size_t &);
    void setMaximumSize(int, int);

    void setMinimumSize(const Size_t &);
    void setMinimumSize(int, int);

    void setPosition(const Point_t &);
    void setPosition(int, int);

    void minimize();
    void maximize();
    void raise();

    void bordered(bool);
    void grabMouse(bool);
    void resizeable(bool);
    void setOpacity(float);

private:
    SDL_Window *m_window = nullptr;
};

#endif    // !WINDOW_HPP
