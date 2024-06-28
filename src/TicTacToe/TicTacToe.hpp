#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "../Lib/Game.hpp"
#include "../Lib/Point.cpp"

class TicTacToe : public Game_t {
public:
    TicTacToe();

private:
    Color_t m_background_color;

    static constexpr int m_cells_cols = 3;

    enum MarkType { NO_MARK, X_MARK, O_MARK };

    int     m_cells[m_cells_cols][m_cells_cols];
    Size_t  m_cell_size;
    Point_t m_grid_start;
    int     m_grid_spacing = 4;

private:
    void calcSizes();
    void render() override;
    void onKeyPressEvent(const SDL_Keysym &) override;
};

#endif    // !TICTACTOE_HPP
