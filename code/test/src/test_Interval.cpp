#include "utils/Interval.hpp"
#include "test/test_utils.hpp"
#include <cmath>

static void _test()
{
    // Test basic constructor and accessors
    Interval ivl{2.0, 5.0};
    EqualOrThrow("ivl.lo =? 2", ivl.lo, 2.0);
    EqualOrThrow("ivl.hi =? 5", ivl.hi, 5.0);
    EqualOrThrow("ivl.Width() =? 3", ivl.Width(), 3.0);
    EqualOrThrow("ivl.Center() =? 3.5", ivl.Center(), 3.5);
    
    // Test Contains()
    TrueOrThrow("ivl.Contains(3) =? true", ivl.Contains(3.0));
    TrueOrThrow("ivl.Contains(2) =? true", ivl.Contains(2.0));
    TrueOrThrow("ivl.Contains(5) =? true", ivl.Contains(5.0));
    FalseOrThrow("ivl.Contains(1) =? false", ivl.Contains(1.0));
    FalseOrThrow("ivl.Contains(6) =? false", ivl.Contains(6.0));
    
    // Test OI() static method
    Interval unit = Interval::OI();
    EqualOrThrow("OI.lo =? 0", unit.lo, 0.0);
    EqualOrThrow("OI.hi =? 1", unit.hi, 1.0);
    
    // Test Normalize()
    Interval ivl2{10.0, 20.0};
    EqualOrThrow("Normalize(15) =? 0.5", ivl2.Normalize(15.0), 0.5);
    EqualOrThrow("Normalize(10) =? 0", ivl2.Normalize(10.0), 0.0);
    EqualOrThrow("Normalize(20) =? 1", ivl2.Normalize(20.0), 1.0);
    EqualOrThrow("Normalize(12.5 to -1..1) =? -0.5", 
                 ivl2.Normalize(12.5, -1.0, 1.0), -0.5);
    
    // Test Modulo()
    Interval modIvl{0.0, 10.0};
    EqualOrThrow("Modulo(5) =? 5", modIvl.Modulo(5.0), 5.0);
    EqualOrThrow("Modulo(15) =? 5", modIvl.Modulo(15.0), 5.0);
    EqualOrThrow("Modulo(-5) =? 5", modIvl.Modulo(-5.0), 5.0);
    EqualOrThrow("Modulo(25) =? 5", modIvl.Modulo(25.0), 5.0);
    
    // Test ModDist()
    Interval distIvl{0.0, 360.0};  // Like degrees
    EqualOrThrow("ModDist(10, 20) =? 10", distIvl.ModDist(10.0, 20.0), 10.0);
    EqualOrThrow("ModDist(350, 10, wrap=true) =? 20", distIvl.ModDist(350.0, 10.0, true), 20.0);
    // Note: wrap=false uses default behavior
    
    // Test Shift()
    Interval shifted = ivl.Shift(2.0);
    EqualOrThrow("Shift(2).lo =? 4", shifted.lo, 4.0);
    EqualOrThrow("Shift(2).hi =? 7", shifted.hi, 7.0);
    
    // Test Stretch()
    Interval stretched = ivl.Stretch(2.0);
    EqualOrThrow("Stretch(2).lo =? 1", stretched.lo, 1.0);
    EqualOrThrow("Stretch(2).hi =? 6", stretched.hi, 6.0);
    
    Interval shrunk = ivl.Stretch(-1.0);
    EqualOrThrow("Stretch(-1).lo =? 2.5", shrunk.lo, 2.5);
    EqualOrThrow("Stretch(-1).hi =? 4.5", shrunk.hi, 4.5);
    
    // Test Contain()
    Interval contained = ivl.Contain(1.0);
    EqualOrThrow("Contain(1).lo =? 1", contained.lo, 1.0);
    EqualOrThrow("Contain(1).hi =? 5", contained.hi, 5.0);
    
    Interval contained2 = ivl.Contain(7.0);
    EqualOrThrow("Contain(7).lo =? 2", contained2.lo, 2.0);
    EqualOrThrow("Contain(7).hi =? 7", contained2.hi, 7.0);
    
    Interval contained3 = ivl.Contain(3.0);
    EqualOrThrow("Contain(3).lo =? 2", contained3.lo, 2.0);
    EqualOrThrow("Contain(3).hi =? 5", contained3.hi, 5.0);
    
    // Test Clip()
    EqualOrThrow("Clip(1) =? 2", ivl.Clip(1.0), 2.0);
    EqualOrThrow("Clip(3) =? 3", ivl.Clip(3.0), 3.0);
    EqualOrThrow("Clip(7) =? 5", ivl.Clip(7.0), 5.0);
    
    // Test UpdateMinMax()
    Interval tracker = Interval::InitMinMax();
    TrueOrThrow("InitMinMax.lo =? inf", std::isinf(tracker.lo) && tracker.lo > 0);
    TrueOrThrow("InitMinMax.hi =? -inf", std::isinf(tracker.hi) && tracker.hi < 0);
    
    tracker.UpdateMinMax(5.0);
    EqualOrThrow("After UpdateMinMax(5).lo =? 5", tracker.lo, 5.0);
    EqualOrThrow("After UpdateMinMax(5).hi =? 5", tracker.hi, 5.0);
    
    tracker.UpdateMinMax(3.0);
    EqualOrThrow("After UpdateMinMax(3).lo =? 3", tracker.lo, 3.0);
    EqualOrThrow("After UpdateMinMax(3).hi =? 5", tracker.hi, 5.0);
    
    tracker.UpdateMinMax(7.0);
    EqualOrThrow("After UpdateMinMax(7).lo =? 3", tracker.lo, 3.0);
    EqualOrThrow("After UpdateMinMax(7).hi =? 7", tracker.hi, 7.0);
    
    // Test MinMax() static method
    std::vector<double> values = {1.0, 3.0, 2.0, 5.0, 4.0};
    Interval fromArray = Interval::MinMax(values);
    EqualOrThrow("MinMax([1,3,2,5,4]).lo =? 1", fromArray.lo, 1.0);
    EqualOrThrow("MinMax([1,3,2,5,4]).hi =? 5", fromArray.hi, 5.0);
    
    // Test Limits()
    auto limits = ivl.Limits();
    EqualOrThrow("Limits().first =? 2", limits.first, 2.0);
    EqualOrThrow("Limits().second =? 5", limits.second, 5.0);
    
    // Test free function Interpolate()
    Interval in{0.0, 100.0};
    Interval out{0.0, 1.0};
    EqualOrThrow("Interpolate(50) =? 0.5", Interpolate(50.0, in, out), 0.5);
    EqualOrThrow("Interpolate(0) =? 0", Interpolate(0.0, in, out), 0.0);
    EqualOrThrow("Interpolate(100) =? 1", Interpolate(100.0, in, out), 1.0);
    
    // Test with different output range
    Interval out2{-10.0, 10.0};
    EqualOrThrow("Interpolate(50 to -10..10) =? 0", Interpolate(50.0, in, out2), 0.0);
    EqualOrThrow("Interpolate(75 to -10..10) =? 5", Interpolate(75.0, in, out2), 5.0);
}

void test_Interval()
{
    RunTest(
        "Interval",
        _test
    );
}