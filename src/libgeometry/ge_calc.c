#include <libgeometry/ge_calc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_CIRCLES 10

int parser(
        int num_circles, char input[][MAX_INPUT_LENGTH], struct Circle* circles)
{
    for (int i = 0; i < num_circles; i++) {
        if (strncmp(input[i], "circle(", 7) != 0) {
            printf("Error: Input string must start with 'circle('\n");
            return 1;
        }

        char* p1 = input[i] + 7;
        char* p2 = strchr(p1, ' ');
        if (!p2) {
            printf("Error: Missing ' ' after x coordinate in input string\n");
            return 1;
        }
        *p2++ = '\0';
        float c_x = atof(p1);

        p1 = p2;
        p2 = strchr(p1, ',');
        if (!p2) {
            printf("Error: Missing ', ' after x coordinate in input string\n");
            return 1;
        }
        *p2++ = '\0';
        float c_y = atof(p1);

        p1 = p2;
        p2 = strchr(p1, ')');
        if (!p2) {
            printf("Error: Missing ')' after radius in input string\n");
            return 1;
        }
        *p2 = '\0';
        float c_r = atof(p1);

        circles[i].x = c_x;
        circles[i].y = c_y;
        circles[i].r = c_r;
    }

    return 0;
}

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
