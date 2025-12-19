#pragma once

#include <vector>

class Interval
{
public:
    double lo, hi;
    
    // Constructors
    Interval(double lo, double hi);
    
    // Static factory methods
    static Interval OI();
    static Interval InitMinMax();
    static Interval MinMax(std::vector<double> const& array);
    
    // Accessors
    double Width() const;
    double Center() const;
    
    // Operations
    bool Contains(double x) const;
    double Normalize(double x, double outMin = 0., double outMax = 1.) const;
    double Modulo(double x) const;
    double ModDist(double a, double b, bool wrap = false) const;
    
    // Transformations
    Interval Shift(double value) const;
    Interval Stretch(double value) const;
    Interval Contain(double value) const;
    double Clip(double value) const;
    
    // Utility
    void UpdateMinMax(double value);
    std::pair<double, double> Limits() const;
};

// Free function for interpolation
double Interpolate(double x, Interval const& ivlIn, Interval const& ivlOut);
