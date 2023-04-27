#include <../thirdparty/ctest.h>
#include <libgeometry/ge_calc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

CTEST(circle_area, correct_input)
{
    const float radius = 5.0;
    const float expected_area = 78.539816;

    const float result = circle_area(radius);

    ASSERT_DBL_NEAR(expected_area, result);
}
CTEST(circle_area, negative_radius)
{
    const float radius = -5.0;
    const float expected_area = 0.0;

    const float result = circle_area(radius);

    ASSERT_DBL_NEAR(expected_area, result);
}

CTEST(circle_perimeter, correct_input)
{
    const float radius = 5.0;
    const float expected_perimeter = 31.415926;

    const float result = circle_perimeter(radius);

    ASSERT_DBL_NEAR(expected_perimeter, result);
}

CTEST(circle_perimeter, negative_radius)
{
    const float radius = -5.0;
    const float expected_perimeter = 0.0;

    const float result = circle_perimeter(radius);

    ASSERT_DBL_NEAR(expected_perimeter, result);
}

CTEST(input_test, correct_input)
{
    char input[MAX_LEN];
    strcpy(input, "circle(4 2,10)");

    char inputs[1][MAX_LEN];
    strcpy(inputs[0], input);

    struct Circle circles[1];
    int result = parser(1, inputs, circles);
    ASSERT_EQUAL(0, result);
}

CTEST(input_test, incorrect_input)
{
    char input[MAX_LEN];
    strcpy(input, "circle (228 1337, 1.5)");

    char inputs[1][MAX_LEN];
    strcpy(inputs[0], input);

    struct Circle circles[1];
    int result = parser(1, inputs, circles);
    ASSERT_EQUAL(1, result);
}

CTEST(input_test, another_input)
{
    char input[MAX_LEN];
    strcpy(input, "circle(");

    char inputs[1][MAX_LEN];
    strcpy(inputs[0], input);

    struct Circle circles[1];
    int result = parser(1, inputs, circles);
    ASSERT_EQUAL(1, result);
}

CTEST(input_test, incorrect_circle_name_input)
{
    char input[MAX_LEN];
    strcpy(input, "ccle(");

    char inputs[1][MAX_LEN];
    strcpy(inputs[0], input);

    struct Circle circles[1];
    int result = parser(1, inputs, circles);
    ASSERT_EQUAL(1, result);
}