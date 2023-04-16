#include "../libgeometry/ge_calc.h"
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int main()
{
    char input[MAX_INPUT_LENGTH];
    float x, y, radius;

    while (1) {
        printf("Input 'circle(x y, radius)': ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        if (sscanf(input, "circle(%f %f, %f)", &x, &y, &radius) == 3) {
            printf("x,y: (%.2f, %.2f)\n", x, y);
            printf("Radius: %.2f", radius);
            break;
        } else {
            printf("Error. Try again\n");
            return 0;
        }
    }
    float area = circle_area(radius);
    float perimeter = circle_perimeter(radius);
    printf("\nArea: %f", area);
    printf("\nPerimeter: %f\n", perimeter);
    return 0;
}