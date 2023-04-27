#pragma once

#define pi 3.14159265359
#define MAX_INPUT_LENGTH 100
#define MAX_CIRCLES 10

float circle_area(float r);

float circle_perimeter(float r);
struct Circle {
    float x;
    float y;
    float r;
    char name;
};

int parser(
        int num_circles,
        char input[][MAX_INPUT_LENGTH],
        struct Circle* circles);
