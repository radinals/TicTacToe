//
#include "PointF.hpp"
#include <cmath>

PointF_t::PointF_t(float x, float y)
{
    x = x;
    y = y;
}

PointF_t
PointF_t::operator+(const PointF_t &other) const
{
    return PointF_t(x + other.x, y + other.y);
}

PointF_t
PointF_t::operator+(float scalar) const
{
    return PointF_t(x + scalar, y + scalar);
}

PointF_t
PointF_t::operator-(const PointF_t &other) const
{
    return PointF_t(x - other.x, y - other.y);
}

PointF_t
PointF_t::operator-(float scalar) const
{
    return PointF_t(x - scalar, y - scalar);
}

PointF_t
PointF_t::operator*(const PointF_t &other) const
{
    return PointF_t(x * other.x, y * other.y);
}

PointF_t
PointF_t::operator*(float scalar) const
{
    return PointF_t(x * scalar, y * scalar);
}

PointF_t
PointF_t::operator/(const PointF_t &other) const
{
    return PointF_t(x / other.x, y / other.y);
}

PointF_t
PointF_t::operator/(float scalar) const
{
    return PointF_t(x / scalar, y / scalar);
}

PointF_t
PointF_t::operator%(const PointF_t &other) const
{
    // return PointF_t(x % other.x, y % other.y);
    return PointF_t();
}

PointF_t
PointF_t::operator%(float scalar) const
{
    // return PointF_t(x % scalar, y % scalar);
    return PointF_t();
}

PointF_t &
PointF_t::operator+=(const PointF_t &other)
{
    x += other.x;
    y += other.y;
    return *this;
}

PointF_t &
PointF_t::operator+=(float scalar)
{
    x += scalar;
    y += scalar;
    return *this;
}

PointF_t &
PointF_t::operator-=(const PointF_t &other)
{
    x += other.x;
    y += other.y;
    return *this;
}

PointF_t &
PointF_t::operator-=(float scalar)
{
    x -= scalar;
    y -= scalar;
    return *this;
}

PointF_t &
PointF_t::operator*=(const PointF_t &other)
{
    x *= other.x;
    y *= other.y;
    return *this;
}

PointF_t &
PointF_t::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

PointF_t &
PointF_t::operator/=(const PointF_t &other)
{
    x /= other.x;
    y /= other.y;
    return *this;
}

PointF_t &
PointF_t::operator/=(float scalar)
{
    x /= scalar;
    y /= scalar;
    return *this;
}

PointF_t &
PointF_t::operator=(const PointF_t &other)
{
    x = other.x;
    y = other.y;
    return *this;
}

bool
PointF_t::operator==(const PointF_t &other) const
{
    return (x == other.x) && (y == other.y);
}

bool
PointF_t::operator!=(const PointF_t &other) const
{
    return (x != other.x) || (y != other.y);
}
