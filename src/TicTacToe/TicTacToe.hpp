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
    enum Players { NONE, HUMAN, CPU };

    Players m_turn = HUMAN;

    int     m_cells[m_cells_cols][m_cells_cols];
    Size_t  m_cell_size;
    Point_t m_grid_start;
    Rect_t  m_selected;
    Rect_t  m_grid_area;
    int     m_grid_spacing = 4;
    Size_t  m_window_size;
    Rect_t  m_mark_pos;
    bool    m_mark = false;
    Players m_player_won = NONE;
    size_t m_cells_filled = 0;
    MarkType m_player_mark = X_MARK;
    MarkType m_cpu_mark = O_MARK;

private:
    void reset();
    void fillCells();
    Players getWinner();
    int randomRange(int,int);
    void calcSizes();
    void render() override;
    void onKeyPressEvent(const SDL_Keysym &) override;
    void onWindowResize(const Size_t &) override;
};

#endif    // !TICTACTOE_HPP
