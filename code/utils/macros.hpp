#include <cmath>

#define ABS(x)      (((x) > 0) ? (x) : -(x))
#define SIGN(x)     (((x) > 0) - ((x) < 0))
#define PI          3.141592653589793116
#define MOD(x,n)    (std::fmod(std::fmod(x,n) + n, n))
#define MOD2PI(x)   (MOD(x,6.283185307179586232))
#define Rad4Deg(x)  (PI * (x) / 180.)
#define Deg4Rad(x)  (180. * (x) / PI)