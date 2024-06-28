#ifndef SIZE_HPP
#define SIZE_HPP

class Size_t {
public:
    Size_t() { }
    Size_t(int, int);
    Size_t(const Size_t &);

    int w = 0, h = 0;
};

#endif    // !SIZE_HPP
