#pragma once

#include <array>
#include "utils/Jsonable.hpp"

class Vec2 : public Jsonable<Vec2>
{
public:
    double x, y;

    // Constructors
    Vec2(double, double);
    
    // JSON serialization (requires JSON library)
    void WriteJson(json& jOut) const override;
    void ReadJson (json const& jIn ) override;
    
    // Static methods
    static Vec2 Zeros();

    static Vec2 Polar(double angle);

    // Member functions
    double Length() const;
    Vec2 Rotated(double angle) const;
    Vec2 Unit() const;
    double Dot(const Vec2& v) const;
    double Argument() const;

    // Arithmetic operators
    Vec2 operator+(const Vec2& other) const;
    Vec2 operator-(const Vec2& other) const;
    Vec2 operator*(double scalar) const;
    Vec2 operator/(double scalar) const;
    Vec2 operator-() const;
};

inline Vec2 operator*(double scalar, Vec2 const& v)
{
    return v * scalar;
}