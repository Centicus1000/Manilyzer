#include "arc/Arc.hpp"
#include "test/test_utils.hpp"

static void _test()
{
    Arc a{0., 0., 0., 1., PI};

    EqualOrThrow("a.straight =? false", a.IsStraight(), 0.);
    EqualOrThrow("a.ca =? PI", a.ca(), PI);

    Vec2 cp = a.CenterPoint();
    EqualOrThrow("a.cp.x =? 0", cp.x, 0.);
    EqualOrThrow("a.cp.y =? 1", cp.y, 1.);

    Vec2 p05 = a.AtPercent(.5);
    EqualOrThrow("a@p05.x =? 1", p05.x, 1.);
    EqualOrThrow("a@p05.y =? 1", p05.y, 1.);

    Vec2 end = a.end();
    EqualOrThrow("a.end.x =? 0", end.x, 0);
    EqualOrThrow("a.end.y =? 2", end.y, 2);
}

void test_Arc()
{
    RunTest(
        "Arc",
        _test
    );
}