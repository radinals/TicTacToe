#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <cstdint>
#include <cstdlib>

#include "Color.hpp"
#include "Renderer.hpp"
#include "Window.hpp"
#include <sched.h>

#include "Game.hpp"

#define DEFAULT_WIDTH       800
#define DEFAULT_HEIGHT      600
#define DEFAULT_WINDOW_NAME "FOOBAR"

Game_t::~Game_t() { SDL_Quit(); }

int
Game_t::run()
{
    m_run = true;

    SDL_Event event;

    while (m_run) {
        uint32_t frame_start = SDL_GetTicks();

        while (SDL_PollEvent(&event)) { eventDispatch(&event); }

        m_renderer->setColor(m_background_color);
        m_renderer->clear();

        render();

        m_renderer->present();

        uint32_t frame_time = SDL_GetTicks() - frame_start;

        if (frame_time < m_frame_rate) { SDL_Delay(m_frame_rate - frame_time); }
    }

    return m_exit_code;
}

void
Game_t::initSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) { exit(0); }

    m_window = new Window_t(DEFAULT_WINDOW_NAME,
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            DEFAULT_WIDTH,
                            DEFAULT_HEIGHT,
                            SDL_WINDOW_SHOWN);

    if (!m_window->getWindow()) { exit(0); }

    m_renderer
        = new Renderer_t(m_window->getWindow(), -1, SDL_RENDERER_ACCELERATED);

    if (!m_renderer->getRenderer()) { exit(0); }
}

void
Game_t::setBackgroundColor(const Color_t &color)
{
    m_background_color = color;
}

void
Game_t::eventDispatch(const SDL_Event *const event)
{
    switch (event->type) {
        case SDL_KEYDOWN:
            onKeyPressEvent(event->key.keysym);
            break;
        case SDL_KEYUP:
            onKeyReleaseEvent(event->key.keysym);
            break;
        case SDL_QUIT:
            onQuitEvent();
            break;
        case SDL_WINDOWEVENT:
            switch (event->window.event) {
                case SDL_WINDOWEVENT_RESIZED:
                    onWindowResize(
                        Size_t(event->window.data1, event->window.data2));
                    break;
                default:
                    break;
            }
            break;
        // case SDL_DISPLAYEVENT:
        //     break;
        default:
            break;
    }
}
