#include "utils/Interval.hpp"

#include "utils/macros.hpp"
#include <limits>

Interval::Interval(double _lo, double _hi)
: lo(_lo), hi(_hi)
{}

Interval Interval::OI()
{
    return {0., 1.};
}

Interval Interval::InitMinMax()
{
    double inf = std::numeric_limits<double>::infinity();
    return {inf, -inf};
}

Interval Interval::MinMax(std::vector<double> const& array)
{
    Interval ivl = InitMinMax();
    for (auto x : array)
    {
        ivl.UpdateMinMax(x);
    }
    return ivl;
}

double Interval::Width() const
{
    return hi - lo;
}

double Interval::Center() const 
{
    return .5 * (hi + lo);
}

bool Interval::Contains(double x) const
{
    return (lo <= x) && (x <= hi);
}

double Interval::Normalize(double x, double oMin, double oMax) const
{
    return Interpolate(x, *this, Interval(oMin, oMax));
}

double Interval::Modulo(double x) const
{
    return MOD(x-lo, Width()) + lo;
}

double Interval::ModDist(double a, double b, bool wrap) const 
{
    if (wrap)
    {
        auto shifted = Shift(Width() / 2);
        return MIN(
            ModDist(a,b), shifted.ModDist(a,b)
        ); // recursive call, without wrap
    }
    return ABS(Modulo(a) - Modulo(b));
}

Interval Interval::Shift(double x) const
{
    return {lo + x, hi + x};
}

Interval Interval::Stretch(double x) const
{
    return {lo - .5 * x, hi + .5 * x};
}

Interval Interval::Contain(double x) const
{
    return {MIN(lo, x), MAX(hi, x)};
}

double Interval::Clip(double x) const
{
    return MAX(lo, MIN(hi, x));
}

void Interval::UpdateMinMax(double x)
{
    lo = MIN(lo, x);
    hi = MAX(hi, x);
}

std::pair<double, double> Interval::Limits() const
{
    return {lo, hi};
}

double Interpolate
(
    double x, 
    Interval const& ivlIn, 
    Interval const& ivlOut
)
{
    return (x - ivlIn.lo) / (ivlIn.hi - ivlIn.lo) * (ivlOut.hi - ivlOut.lo) + ivlOut.lo;
}

