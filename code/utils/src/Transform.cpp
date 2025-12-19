#include "utils/Transform.hpp"

///
Transform::Transform(
    double x, 
    double y, 
    double r
) : 
    x(x), y(y), r(r) 
{}

Transform Transform::Identity() 
{
    return Transform(0, 0, 0);
}

void Transform::WriteJson(json& jOut) const
{
    jOut = json::array({x, y, r});
}

void Transform::ReadJson (json const& jIn )
{
    x = jIn[0].get<double>();
    y = jIn[1].get<double>();
    r = jIn[2].get<double>();
}
    
Vec2 Transform::p() const 
{
    return Vec2(x, y);
}

Vec2 Transform::v() const 
{
    return Vec2::Polar(r);
}

Transform Transform::Dot(Transform const& other) const
{
    Vec2 pNew = p().Rotated(other.r) + other.p();
    return Transform{
        pNew.x, 
        pNew.y, 
        r + other.r
    };
}

Transform Transform::Scaled(double scale) const
{
    return Transform{
        x * scale,
        y * scale,
        r * scale
    };
}


// Arithmetic operators
Transform Transform::operator+(Transform const& other) const {
    return Transform{
        x + other.x,
        y + other.y,
        r + other.r
    };
}

Transform Transform::operator-(Transform const& other) const 
{
    return Transform{
        x - other.x,
        y - other.y,
        r - other.r
    };
}

Transform Transform::operator-() const 
{
    return Transform{-x, -y, -r};
}
