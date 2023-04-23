#include <libgeometry/ge_calc.h>
#include <math.h>

float circle_area(float r)
{
    if (r > 0) {
        return M_PI * r * r;
    } else {
        return 0;
    }
}

float circle_perimeter(float r)
{
    if (r > 0) {
        return 2 * M_PI * r;
    } else {
        return 0;
    }
}
