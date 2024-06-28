#ifndef POINTF_HPP
#define POINTF_HPP

#include <SDL2/SDL_rect.h>

class PointF_t : public SDL_FPoint {
public:
    explicit PointF_t() { }
    explicit PointF_t(float, float);

    PointF_t operator+(const PointF_t &) const;
    PointF_t operator+(float) const;

    PointF_t operator-(const PointF_t &) const;
    PointF_t operator-(float) const;

    PointF_t operator*(const PointF_t &) const;
    PointF_t operator*(float) const;

    PointF_t operator/(const PointF_t &) const;
    PointF_t operator/(float) const;

    PointF_t operator%(const PointF_t &) const;
    PointF_t operator%(float) const;

    PointF_t &operator+=(const PointF_t &);
    PointF_t &operator+=(float);

    PointF_t &operator-=(const PointF_t &);
    PointF_t &operator-=(float);

    PointF_t &operator*=(const PointF_t &);
    PointF_t &operator*=(float);

    PointF_t &operator/=(const PointF_t &);
    PointF_t &operator/=(float);

    PointF_t &operator=(const PointF_t &);

    bool operator==(const PointF_t &) const;
    bool operator!=(const PointF_t &) const;
};

#endif    // !POINTF_HPP
