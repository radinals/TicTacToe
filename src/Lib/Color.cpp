#include "Color.hpp"

Color_t::Color_t(const char *const str) { fromHexStr(str); }

Color_t::Color_t(const std::string &hex) { fromHexStr(hex.c_str()); }

Color_t::Color_t(uint32_t hex) { fromHex(hex); }

void
Color_t::setR(int r)
{
    m_r = r;
}

void
Color_t::setG(int g)
{
    m_g = g;
}

void
Color_t::setB(int b)
{
    m_b = b;
}

void
Color_t::setA(int a)
{
    m_a = a;
}

int
Color_t::getR() const
{
    return m_r;
}

int
Color_t::getG() const
{
    return m_g;
}

int
Color_t::getB() const
{
    return m_b;
}

int
Color_t::getA() const
{
    return m_a;
}

Color_t &
Color_t::operator=(const char *const color)
{
    fromHexStr(color);
    return *this;
}

void
Color_t::fromHex(uint32_t hex)
{
    m_r = ((hex >> 16) & 0xFF) / 255.0F;    // Extract the RR byte
    m_g = ((hex >> 8) & 0xFF) / 255.0F;     // Extract the GG byte
    m_b = ((hex) & 0xFF) / 255.0F;          // Extract the BB byte
}

void
Color_t::fromHexStr(const char hex[])
{
    sscanf(hex, "#%02x%02x%02x", &m_r, &m_g, &m_b);
}
