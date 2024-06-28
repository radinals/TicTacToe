#include "TicTacToe/TicTacToe.hpp"

int
main(int argc, char* argv[])
{
    TicTacToe G;
    G.initSDL();
    return G.run();
}
