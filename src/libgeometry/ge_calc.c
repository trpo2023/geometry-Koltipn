#include <libgeometry/ge_calc.h>

float circle_area(float r)
{
    if (r > 0) {
        return pi * r * r;
    } else {
        return 0;
    }
}

float circle_perimeter(float r)
{
    if (r > 0) {
        return 2 * pi * r;
    } else {
        return 0;
    }
}
