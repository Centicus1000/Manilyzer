#pragma once

#include <vector>

/**
 * @class Interval
 * @brief Represents a mathematical interval [lo, hi] with various operations
 * 
 * This class provides functionality for working with intervals, including
 * normalization, modulo operations, min/max tracking, and transformations.
 * All intervals are inclusive on both ends (closed interval).
 */
class Interval
{
public:
    // ----------------------------------------------
    // Attributes

    /// Lower bound of the interval
    double lo;
    
    /// Upper bound of the interval
    double hi;
    
    // ----------------------------------------------
    // Constructor

    /**
     * @brief Constructs an Interval with given bounds
     * @param lo Lower bound of the interval
     * @param hi Upper bound of the interval
     */
    Interval(double lo, double hi);
    
    // ----------------------------------------------
    // Static factory methods
    
    /**
     * @brief Creates the unit interval [0, 1]
     * @return Interval from 0 to 1 inclusive
     * 
     * Ethymology: The letter "O" refers to zero, and the letter "I" refers to one.
     */
    static Interval OI();
    
    /**
     * @brief Creates an interval initialized for min/max tracking
     * 
     * Initializes with (infinity, -infinity) so that UpdateMinMax()
     * can properly track minimum and maximum values. Useful for
     * dynamically building intervals from data.
     * 
     * @return Interval ready for min/max updates
     */
    static Interval InitMinMax();
    
    /**
     * @brief Creates an interval containing the min and max of an array
     * @param array Vector of values to find min/max from
     * @return Interval spanning [min(array), max(array)]
     */
    static Interval MinMax(std::vector<double> const& array);
    
    // ----------------------------------------------
    // Accessors
    
    /**
     * @brief Gets the width of the interval
     * @return Difference between hi and lo (hi - lo)
     */
    double Width() const;
    
    /**
     * @brief Gets the center point of the interval
     * @return Average of lo and hi ((lo + hi) / 2)
     */
    double Center() const;
    
    // ----------------------------------------------
    // Operations
    
    /**
     * @brief Checks if a value is within the interval
     * @param x Value to check
     * @return True if lo ≤ x ≤ hi, false otherwise
     */
    bool Contains(double x) const;

    /**
     * @brief Clips a value to the interval bounds
     * @param value Value to clip
     * @return lo if value < lo, hi if value > hi, otherwise value unchanged
     */
    double Clip(double value) const;
    
    /**
     * @brief Normalizes a value from this interval to another interval
     * 
     * Maps x from [lo, hi] to [outMin, outMax] linearly. If x is outside
     * the input interval, it will be extrapolated.
     * 
     * @param x Value to normalize
     * @param outMin Lower bound of output interval (default: 0)
     * @param outMax Upper bound of output interval (default: 1)
     * @return Value mapped to output interval
     */
    double Normalize(double x, double outMin = 0., double outMax = 1.) const;
    
    /**
     * @brief Computes x modulo the interval width with offset
     * 
     * Maps x into the interval [lo, hi] by taking modulo of the width
     * and adding the lower bound. Equivalent to:
     *   mod(x - lo, width) + lo
     * 
     * @param x Value to compute modulo for
     * @return Value wrapped into the interval
     */
    double Modulo(double x) const;
    
    /**
     * @brief Computes distance between two values modulo the interval
     * 
     * First maps both values into the interval using Modulo(), then
     * computes the absolute difference. If wrap=true, considers the
     * wrap-around distance and returns the minimum.
     * 
     * @param a First value
     * @param b Second value
     * @param wrap If true, considers wrap-around distance (default: false)
     * @return Distance between the modulo-mapped values
     */
    double ModDist(double a, double b, bool wrap = false) const;
    
    // ----------------------------------------------
    // Transformations
    
    /**
     * @brief Shifts the interval by a constant value
     * @param value Amount to add to both lo and hi
     * @return New interval [lo + value, hi + value]
     */
    Interval Shift(double value) const;
    
    /**
     * @brief Stretches the interval symmetrically
     * 
     * Increases/decreases the width by moving both bounds outward/inward
     * equally. Negative values decrease the width.
     * 
     * @param value Amount to add to width (can be negative)
     * @return New interval [lo - value/2, hi + value/2]
     */
    Interval Stretch(double value) const;
    
    /**
     * @brief Creates interval containing both original interval and value
     * 
     * Returns the smallest interval that contains both the original
     * interval and the given value. If value is already within the
     * interval, returns a copy of the original.
     * 
     * @param value Value to include in the interval
     * @return Interval that contains both original bounds and value
     */
    Interval Contain(double value) const;
    
    // ----------------------------------------------
    // Utility
    
    /**
     * @brief Updates interval to include a value (min/max tracking)
     * 
     * Expands the interval if necessary to include the given value.
     * Updates lo to min(current lo, value) and hi to max(current hi, value).
     * 
     * @param value Value to include in the interval
     */
    void UpdateMinMax(double value);
    
    /**
     * @brief Gets the interval bounds as a pair
     * @return Pair containing (lo, hi)
     */
    std::pair<double, double> Limits() const;
};


/**
 * @brief Linear interpolation between intervals
 * 
 * Maps x from input interval to output interval linearly.
 * Equivalent to ivlOut.Normalize(x, ivlIn).
 * 
 * @param x Value to interpolate
 * @param ivlIn Input interval
 * @param ivlOut Output interval
 * @return Value mapped from ivlIn to ivlOut
 */
double Interpolate(double x, Interval const& ivlIn, Interval const& ivlOut);