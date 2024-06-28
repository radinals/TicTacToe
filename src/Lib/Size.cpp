#include "Size.hpp"

Size_t::Size_t(int w_, int h_)
{
    w = w_;
    h = h_;
}

Size_t::Size_t(const Size_t &size)
{
    w = size.w;
    h = size.h;
}
