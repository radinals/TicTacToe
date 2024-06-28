#ifndef GAME_HPP
#define GAME_HPP

#include "Color.hpp"
#include "Rect.hpp"
#include "Renderer.hpp"
#include "Size.hpp"
#include "Window.hpp"
#include <SDL2/SDL_events.h>

class Game_t {
public:
    Game_t() {};
    virtual ~Game_t();

    int  run();
    void quit(int n)
    {
        m_exit_code = n;
        m_run       = false;
    };
    virtual void initSDL();

private:
    int     m_frame_rate = 1000 / 15;
    int     m_exit_code  = 0;
    bool    m_run        = false;
    Color_t m_background_color;

protected:
    Window_t   *m_window   = nullptr;
    Renderer_t *m_renderer = nullptr;

protected:
    void         setBackgroundColor(const Color_t &);
    virtual void eventDispatch(const SDL_Event *const);
    virtual void onKeyPressEvent(const SDL_Keysym &) { }
    virtual void onKeyReleaseEvent(const SDL_Keysym &) { }
    virtual void onQuitEvent() { m_run = false; }
    virtual void render() { }

    virtual void onWindowResize(const Size_t &) { }

    // virtual void onMouseMove();
    // virtual void onMouseClick();
    // virtual void onMouseScroll();

    // virtual void onWindowShown();
    // virtual void onWindowHide();
    // virtual void onWindowExposed();
    // virtual void onWindowMove(Point_t);
    // virtual void onWindowResize(Size_t);
    // virtual void onWindowSizeChanged();
    // virtual void onWindowMinimized();
    // virtual void onWindowMaximized();
    // virtual void onWindowRestored();
    // virtual void onWindowEnter();
    // virtual void onWindowLeave();
    // virtual void onWindowFocusGained();
    // virtual void onWindowFocusLost();
    // virtual void onWindowClose();
    // virtual void onWindowTakeFocus();
    // virtual void onWindowDisplayChanged();

    // void resize(int, int);
    // void resize(Size_t);
    //
    // void move(int, int);
    // void move(Point_t);
};

#endif    // !GAME_HPP
