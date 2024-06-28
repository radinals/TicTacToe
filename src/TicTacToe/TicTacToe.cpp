#include "TicTacToe.hpp"
#include <iostream>

TicTacToe::TicTacToe()
{
    setBackgroundColor(Color_t("#000000"));

    for (size_t i = 0; i < m_cells_cols; i++) {
        for (size_t j = 0; j < m_cells_cols; j++) { m_cells[i][j] = 0; }
    }

    m_cells[0][0] = MarkType::X_MARK;
}

void
TicTacToe::render()
{
    calcSizes();

    // std::cout << "DRAWING\n";

    Point_t pos = m_grid_start;

    for (size_t i = 0; i < m_cells_cols; i++) {
        pos.x = m_grid_start.x;
        for (size_t j = 0; j < m_cells_cols; j++) {
            m_renderer->setColor(Color_t("#FFFFFF"));
            m_renderer->drawFillRect(pos, m_cell_size);
            if (m_cells[i][j] == MarkType::O_MARK) {
                Rect_t r(pos.x, pos.y, m_cell_size.w, m_cell_size.h);
                m_renderer->setColor(Color_t("#FFF000"));
                m_renderer->drawLine(r.getTopLeft(), r.getBottomRight());
                m_renderer->drawLine(r.getTopRight(), r.getBottomLeft());
            } else if (m_cells[i][j] == MarkType::X_MARK) {
                Rect_t r(pos.x, pos.y, m_cell_size.w, m_cell_size.h);
                m_renderer->setColor(Color_t("#FF0000"));
                m_renderer->drawLine(r.getTopLeft(), r.getBottomRight());
                m_renderer->drawLine(r.getTopRight(), r.getBottomLeft());
            }

            pos.x += (m_cell_size.w + m_grid_spacing);
        }
        pos.y += (m_cell_size.h + m_grid_spacing);
    }
}

void
TicTacToe::calcSizes()
{
    const Size_t window_size = m_window->getSize();

    int w = window_size.w / float(m_cells_cols);
    int h = window_size.h / float(m_cells_cols);

    m_cell_size = Size_t(w, h);

    m_grid_start.x
        = ((window_size.w / 2.0F) - ((m_cell_size.w * m_cells_cols) / 2.0F))
          - m_grid_spacing;
    m_grid_start.y
        = ((window_size.h / 2.0F) - ((m_cell_size.h * m_cells_cols) / 2.0F))
          - m_grid_spacing;
}

void
TicTacToe::onKeyPressEvent(const SDL_Keysym &)
{
    quit(0);
}
