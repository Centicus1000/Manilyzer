#include "utils/Vec2.hpp"

#include <cmath>

Vec2::Vec2
(
    double _x,
    double _y
) :
    x(_x),
    y(_y)
{}

void Vec2::WriteJson(json& jOut) const
{
    jOut["x"] = x;
    jOut["y"] = y;
}

void Vec2::ReadJson (json const& jIn)
{
    x = jIn["x"].get<double>();
    y = jIn["y"].get<double>();
}

Vec2 Vec2::Zeros()
{
    return {0., 0.};
}

Vec2 Vec2::Polar(double angle)
{
    return {std::cos(angle), std::sin(angle)};
}

// Member functions
double Vec2::Length() const 
{
    return std::sqrt(x * x + y * y);
}

Vec2 Vec2::Rotated(double angle) const 
{
    return {
        std::cos(angle) * x - std::sin(angle) * y,
        std::sin(angle) * x + std::cos(angle) * y
    };
}

Vec2 Vec2::Unit() const
{
    return *this / Length();
}

double Vec2::Dot(const Vec2& v) const 
{
    return x * v.x + y * v.y;
}

double Vec2::Argument() const 
{
    return std::atan2(y, x);
}

// ----------------------------------------------
// Arithmetic operators

Vec2 Vec2::operator+
(const Vec2& other) const 
{
    return {x + other.x, y + other.y};
}

Vec2 Vec2::operator-
(const Vec2& other) const 
{
    return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator*
(double scalar) const 
{
    return {x * scalar, y * scalar};
}

Vec2 Vec2::operator/
(double scalar) const 
{
    return {x / scalar, y / scalar};
}

Vec2 Vec2::operator-
() const 
{
    return {-x, -y};
}