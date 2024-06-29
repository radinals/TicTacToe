#include "TicTacToe.hpp"
#include <SDL2/SDL_keycode.h>
#include <cstring>
#include <iostream>

TicTacToe::TicTacToe() : Game_t()
{
    setBackgroundColor(Color_t("#FFFFFF"));

    for (size_t i = 0; i < m_cells_cols; i++) {
        memset(m_cells, MarkType::NO_MARK, m_cells_cols);
    }

    m_cells[0][0] = MarkType::X_MARK;
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
            // std::cout << "POS: " << pos.x << ' ' << pos.y << '\n';
            // std::cout << "SEL: " << m_selected.x << ' ' << m_selected.y <<
            // '\n';
            m_renderer->drawRect(Point_t(m_selected.getTopLeft().x + 2,
                                         m_selected.getTopLeft().y + 2),
                                 Size_t(m_selected.w - 2, m_selected.h - 4));
            if (pos == m_mark_pos) {
                m_cells[i][j] = (m_cells[i][j] == NO_MARK)  ? MarkType::X_MARK
                                : (m_cells[i][j] == X_MARK) ? MarkType::O_MARK
                                                            : MarkType::NO_MARK;
                m_mark_pos.x  = -1;
                m_mark_pos.y  = -1;
            }
            if (m_cells[i][j] == MarkType::O_MARK) {
                m_renderer->setColor(Color_t("#FFF000"));
                // m_renderer->drawLine(pos.getTopLeft(), pos.getBottomRight());
                // m_renderer->drawLine(pos.getTopRight(), pos.getBottomLeft());
                m_renderer->drawFillRect(pos);
            } else if (m_cells[i][j] == MarkType::X_MARK) {
                Rect_t r(pos.x, pos.y, m_cell_size.w, m_cell_size.h);
                m_renderer->setColor(Color_t("#FF0000"));
                // m_renderer->drawLine(pos.getTopLeft(), pos.getBottomRight());
                // m_renderer->drawLine(pos.getTopRight(), pos.getBottomLeft());
                m_renderer->drawFillRect(pos);
            }

            m_renderer->setColor(Color_t("#FD0DF0"));
            m_renderer->drawRect(m_selected);
            m_renderer->drawRect(Point_t(m_selected.getTopLeft().x + 1,
                                         m_selected.getTopLeft().y + 1),
                                 Size_t(m_selected.w - 2, m_selected.h - 2));

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

    int w = (m_window_size.w / float(m_cells_cols)) - m_grid_spacing * 2;
    int h = (m_window_size.h / float(m_cells_cols)) - m_grid_spacing * 2;

    m_cell_size = Size_t(w, h);

    m_grid_start.x = int((m_window_size.w / 2.0F)
                         - ((m_cell_size.w * m_cells_cols) / 2.0F))
                     - m_grid_spacing;
    m_grid_start.y = int((m_window_size.h / 2.0F)
                         - ((m_cell_size.h * m_cells_cols) / 2.0F))
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
        case SDLK_m:
            m_mark_pos = m_selected;
            break;
        default:
            break;
    }
}
