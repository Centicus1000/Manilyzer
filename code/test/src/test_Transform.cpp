// test_transform.cpp
#include "utils/Transform.hpp"
#include "test/test_utils.hpp"

static void _test()
{
    // ----------------------------------------------
    std::cout << "\tDot: ... " << std::endl;

    Transform A{ 1., 0., Rad4Deg(90.) };
    Transform B{ 0., 1., Rad4Deg(90.) };
    auto C = A.Dot(B);

    EqualOrThrow("C.x =? 0", C.x, 0.);
    EqualOrThrow("C.y =? 2", C.y, 2.);
    EqualOrThrow("C.r =? PI", C.r, PI);


    // ----------------------------------------------
    std::cout << "\tJsonable: ... " << std::endl;

    json j;
    Transform T_before(1.5, 2.5, M_PI);
    T_before.WriteJson(j);
    Transform T_after = Transform::Identity();
    T_after.ReadJson(j);

    EqualOrThrow(
        "before.x =? after.x", T_before.x, T_after.x
    );
    EqualOrThrow(
        "before.y =? after.y", T_before.y, T_after.y
    );
    EqualOrThrow(
        "before.r =? after.r", T_before.r, T_after.r
    );
}

void test_Transform()
{
    RunTest(
        "Transform",
        _test
    );
}