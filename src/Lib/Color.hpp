#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstdint>
#include <string>

class Color_t {
public:
    Color_t() {};
    Color_t(const char *const);
    Color_t(const std::string &);
    Color_t(uint32_t);

    void setR(int);
    void setG(int);
    void setB(int);
    void setA(int);

    int getR() const;
    int getG() const;
    int getB() const;
    int getA() const;

    void loadHex(const char *const);

    Color_t &operator=(const char *const);

    void fromHex(uint32_t);
    void fromHexStr(const char[]);

private:
    int m_r = 0, m_g = 0, m_b = 0, m_a = 255;
};

#endif    // !COLOR_HPP
