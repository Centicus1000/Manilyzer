#include "arc/Arc.hpp"
#include "utils/macros.hpp"

#include <numbers>

Arc::Arc
(
    double _x, double _y, double _a, double _k, double _l
) :
    x(_x), y(_y), a(_a), k(_k), l(_l)
{}

bool Arc::IsStraight() const
{
    return k == 0.;
}

Vec2 Arc::bgn() const
{
    return {x, y};
}

Vec2 Arc::Begin() const
{
    return bgn();
}

double Arc::r() const
{
    return ABS(1. / k);
}

double Arc::Radius() const
{
    return r();
}

double Arc::ca() const
{
    return k * l;
}

double Arc::CentralAngle() const
{
    return ca();
}

Vec2 Arc::cp() const
{
    return bgn() + Vec2::Polar(a + .5 * PI) / k;
}

Vec2 Arc::CenterPoint() const
{
    return cp();
}

Vec2 Arc::AtTangent(double length) const
{
    return bgn() + length * Vec2::Polar(a);
}

Vec2 Arc::AtLength(double length) const
{
    if (IsStraight()) return AtTangent(length);
    return cp() + Vec2::Polar(a - .5 * PI + length * k) / k;
}

Vec2 Arc::AtPercent(double percent) const
{
    return AtLength(percent * l);
}

Vec2 Arc::AtAngle(double angle) const
{
    return cp() + r() * Vec2::Polar(angle);
}

Vec2 Arc::end() const
{
    return AtLength(l);
}

Vec2 Arc::EndPoint() const
{
    return end();
}

double Arc::ex() const
{
    return end().x;
}

double Arc::ey() const
{
    return end().y;
}

bool Arc::Reaches(double angle) const
{
    return ABS(ca()) >= MOD2PI(SIGN(k) * (angle - a) + .5 * PI);
}

void Arc::ApplyT(Transform T)
{
    a += T.r;
    Vec2 bgnNew = bgn().Rotated(T.r) + T.p();
    x = bgnNew.x;
    y = bgnNew.y;
}
