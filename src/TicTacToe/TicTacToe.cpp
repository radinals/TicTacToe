#include "TicTacToe.hpp"
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_timer.h>
#include <cstring>
#include <iostream>
#include <random>

TicTacToe::TicTacToe() : Game_t()
{
    setBackgroundColor(Color_t("#FFFFFF"));
    fillCells();

}

void
TicTacToe::render()
{
    m_window_size = m_window->getSize();
    calcSizes();

    // std::cout << "DRAWING\n";

    Rect_t pos(m_grid_start.x, m_grid_start.y, m_cell_size.w, m_cell_size.h);

    for (size_t i = 0; i < m_cells_cols; i++) {
        pos.x = m_grid_start.x;
        for (size_t j = 0; j < m_cells_cols; j++) {
            m_renderer->setColor(Color_t("#000000"));
            m_renderer->drawFillRect(pos);
            if (m_player_won != NONE || m_cells_filled == (m_cells_cols * m_cells_cols)) {
                SDL_Delay(1000);
                reset();
            } else if (pos == m_mark_pos && m_mark && m_turn == HUMAN && m_player_won == NONE) {
                if (m_cells[i][j] == NO_MARK) {
                    m_cells[i][j] = m_player_mark;
                    m_turn = CPU;
                    m_player_won = getWinner();
                    m_cells_filled++;
                }
                m_mark        = false;
            } else if (m_turn == CPU && m_player_won == NONE ){
                int x = 0, y = 0;
                do {
                    x = randomRange(0, m_cells_cols);
                    y = randomRange(0, m_cells_cols);
                } while(m_cells[y][x] != NO_MARK);
                m_cells[y][x] = m_cpu_mark;
                m_turn = HUMAN;
                m_cells_filled ++;
                m_player_won = getWinner();
            }
            if (m_cells[i][j] == MarkType::O_MARK) {
                m_renderer->setColor(Color_t("#FFF000"));
                m_renderer->drawFillRect(pos);
            } else if (m_cells[i][j] == MarkType::X_MARK) {
                Rect_t r(pos.x, pos.y, m_cell_size.w, m_cell_size.h);
                m_renderer->setColor(Color_t("#FF0000"));
                m_renderer->drawFillRect(pos);
            }

            m_renderer->setColor(Color_t("#FD0DF0"));
            m_renderer->drawFillRect(m_selected);

            pos.x += (m_cell_size.w + m_grid_spacing);
        }
        pos.y += (m_cell_size.h + m_grid_spacing);
    }
}

void
TicTacToe::onWindowResize(const Size_t &size)
{
}

void
TicTacToe::calcSizes()
{
    m_window_size = m_window->getSize();

    int w = int(float(m_window_size.w) / float(m_cells_cols))
            - m_grid_spacing * 2;
    int h = int(float(m_window_size.h) / float(m_cells_cols))
            - m_grid_spacing * 2;

    m_cell_size = Size_t(w, h);

    m_grid_start.x = int((float(m_window_size.w) / 2.0F)
                         - (float(m_cell_size.w * m_cells_cols) / 2.0F))
                     - m_grid_spacing;
    m_grid_start.y = int((float(m_window_size.h) / 2.0F)
                         - (float(m_cell_size.h * m_cells_cols) / 2.0F))
                     - m_grid_spacing;
    m_grid_area.h = m_cell_size.h * m_cells_cols;
    m_grid_area.w = m_cell_size.w * m_cells_cols;
    m_grid_area.x = m_grid_spacing * 2;
    m_grid_area.y = m_grid_spacing * 2;

    static bool init = false;
    if (!init) {
        m_selected = Rect_t(m_grid_start.x, m_grid_start.y, w, h);

        init = true;
    }
}

void
TicTacToe::onKeyPressEvent(const SDL_Keysym &key)
{
    int new_pos = 0;
    switch (key.sym) {
        case SDLK_UP:
            new_pos = (m_selected.y - m_selected.h) - m_grid_spacing;
            if (new_pos >= m_grid_area.getTopLeft().y) {
                m_selected.y = new_pos;
            }
            break;
        case SDLK_DOWN:
            new_pos = (m_selected.y + m_selected.h) + m_grid_spacing;
            if (new_pos <= m_grid_area.getBottomLeft().y) {
                m_selected.y = new_pos;
            }
            break;
        case SDLK_LEFT:
            new_pos = (m_selected.x - m_selected.w) - m_grid_spacing;
            if (new_pos >= m_grid_area.getTopLeft().x) {
                m_selected.x = new_pos;
            }
            break;
        case SDLK_RIGHT:
            new_pos = (m_selected.x + m_selected.w) + m_grid_spacing;
            if (new_pos <= m_grid_area.getTopRight().x) {
                m_selected.x = new_pos;
            }
            break;
        case SDLK_SPACE:
            m_mark_pos = m_selected;
            m_mark     = true;
            break;
        case SDLK_r:
            reset();
        break;
        default:
            break;
    }
}

TicTacToe::Players TicTacToe::getWinner() {
    if (m_cells[0][2] == m_player_mark && m_cells[1][1] == m_player_mark && m_cells[2][0] == m_player_mark) {
        return Players::HUMAN;
    }
    if (m_cells[0][0] == m_player_mark && m_cells[1][1] == m_player_mark && m_cells[2][2] == m_player_mark) {
        return Players::HUMAN;
    }
    if (m_cells[0][0] == m_player_mark && m_cells[0][1] == m_player_mark && m_cells[0][2] == m_player_mark) {
        return Players::HUMAN;
    }
    if (m_cells[1][0] == m_player_mark && m_cells[1][1] == m_player_mark && m_cells[1][2] == m_player_mark) {
        return Players::HUMAN;
    }
    if (m_cells[2][0] == m_player_mark && m_cells[2][1] == m_player_mark && m_cells[2][2] == m_player_mark) {
        return Players::HUMAN;
    }
    if (m_cells[0][0] == m_player_mark && m_cells[1][0] == m_player_mark && m_cells[2][0] == m_player_mark) {
        return Players::HUMAN;
    }
    if (m_cells[0][1] == m_player_mark && m_cells[1][1] == m_player_mark && m_cells[2][1] == m_player_mark) {
        return Players::HUMAN;
    }
    if (m_cells[0][2] == m_player_mark && m_cells[1][2] == m_player_mark && m_cells[2][2] == m_player_mark) {
        return Players::HUMAN;
    }

    if (m_cells[0][2] == m_cpu_mark && m_cells[1][1] == m_cpu_mark && m_cells[2][0] == m_cpu_mark) {
        return Players::CPU;
    }
    if (m_cells[0][0] == m_cpu_mark && m_cells[1][1] == m_cpu_mark && m_cells[2][2] == m_cpu_mark) {
        return Players::CPU;
    }
    if (m_cells[0][0] == m_cpu_mark && m_cells[0][1] == m_cpu_mark && m_cells[0][2] == m_cpu_mark) {
        return Players::CPU;
    }
    if (m_cells[1][0] == m_cpu_mark && m_cells[1][1] == m_cpu_mark && m_cells[1][2] == m_cpu_mark) {
        return Players::CPU;
    }
    if (m_cells[2][0] == m_cpu_mark && m_cells[2][1] == m_cpu_mark && m_cells[2][2] == m_cpu_mark) {
        return Players::CPU;
    }
    if (m_cells[0][0] == m_cpu_mark && m_cells[1][0] == m_cpu_mark && m_cells[2][0] == m_cpu_mark) {
        return Players::CPU;
    }
    if (m_cells[0][1] == m_cpu_mark && m_cells[1][1] == m_cpu_mark && m_cells[2][1] == m_cpu_mark) {
        return Players::CPU;
    }
    if (m_cells[0][2] == m_cpu_mark && m_cells[1][2] == m_cpu_mark && m_cells[2][2] == m_cpu_mark) {
        return Players::CPU;
    }

    return NONE;
}

void TicTacToe::reset() {
    fillCells();
    m_player_won = NONE;
    m_turn = HUMAN;
    m_cells_filled = 0;
}


void TicTacToe::fillCells() {
    for (size_t i = 0; i < m_cells_cols; i++) {
        for (size_t j = 0; j < m_cells_cols; j++) {
            m_cells[i][j] = NO_MARK;
        }
    }
}

int TicTacToe::randomRange(int min,int max) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max); // define the range

    return distr(gen);

}
