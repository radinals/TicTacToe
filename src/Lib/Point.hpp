#ifndef POINT_HPP
#define POINT_HPP

#include <SDL2/SDL_rect.h>

class Point_t : public SDL_Point {
public:
    Point_t() : SDL_Point { 0, 0 } { }
    Point_t(int x, int y) : SDL_Point { x, y } { }

    Point_t operator+(const Point_t &other) const
    {
        return Point_t(x + other.x, y + other.y);
    }

    Point_t operator-(const Point_t &other) const
    {
        return Point_t(x - other.x, y - other.y);
    }

    Point_t operator*(const Point_t &other) const
    {
        return Point_t(x * other.x, y * other.y);
    }

    Point_t operator/(const Point_t &other) const
    {
        return Point_t(x / other.x, y / other.y);
    }

    Point_t operator%(const Point_t &other) const
    {
        return Point_t(x % other.x, y % other.y);
    }

    Point_t operator+(int scalar) const
    {
        return Point_t(x + scalar, y + scalar);
    }

    Point_t operator-(int scalar) const
    {
        return Point_t(x - scalar, y - scalar);
    }

    Point_t operator*(int scalar) const
    {
        return Point_t(x * scalar, y * scalar);
    }

    Point_t operator/(int scalar) const
    {
        return Point_t(x / scalar, y / scalar);
    }

    Point_t operator%(int scalar) const
    {
        return Point_t(x % scalar, y % scalar);
    }

    Point_t &operator+=(const Point_t &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Point_t &operator+=(int scalar)
    {
        x += scalar;
        y += scalar;
        return *this;
    }

    Point_t &operator-=(const Point_t &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Point_t &operator-=(int scalar)
    {
        x -= scalar;
        y -= scalar;
        return *this;
    }

    Point_t &operator*=(const Point_t &other)
    {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    Point_t &operator*=(int scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Point_t &operator/=(const Point_t &other)
    {
        x /= other.x;
        y /= other.y;
        return *this;
    }

    Point_t &operator/=(int scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    Point_t &operator=(const Point_t &other)
    {
        x = other.x;
        y = other.y;
        return *this;
    }

    bool operator==(const Point_t &other) const
    {
        return (x == other.x) && (y == other.y);
    }

    bool operator!=(const Point_t &other) const
    {
        return (x != other.x) || (y != other.y);
    }
};

#endif    // !POINT_HPP
