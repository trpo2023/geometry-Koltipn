#include <libgeometry/ge_calc.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_CIRCLES 10

int main()
{
    char input[MAX_INPUT_LENGTH];
    float x[MAX_CIRCLES], y[MAX_CIRCLES], r[MAX_CIRCLES];
    int num_circles;

    while (1) {
        printf("Enter the number of circles (1-10): ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        if (sscanf(input, "%d", &num_circles) == 1 && num_circles >= 1
            && num_circles <= MAX_CIRCLES) {
            break;
        } else {
            printf("Error. Enter a number between 1 and 10.\n");
            return 0;
        }
    }

    for (int i = 0; i < num_circles; i++) {
        while (1) {
            printf("Enter circle %d (circle(x y,r)): ", i + 1);
            fgets(input, MAX_INPUT_LENGTH, stdin);
            float x_val, y_val, r_val;
            if (sscanf(input, "circle(%f %f,%f)", &x_val, &y_val, &r_val)
                == 3) {
                x[i] = x_val;
                y[i] = y_val;
                r[i] = r_val;
                printf("Circle %d: x,y: (%.2f, %.2f), Radius: %.2f\n",
                       i + 1,
                       x[i],
                       y[i],
                       r[i]);
                break;
            } else {
                printf("Error. Please enter circle in the format 'circle(x "
                       "y,r)'.\n");
                return 0;
            }
        }
    }

    for (int i = 0; i < num_circles; i++) {
        float area = circle_area(r[i]);
        float perimeter = circle_perimeter(r[i]);
        printf("\nCircle %d:\nArea: %f\nPerimeter: %f\n",
               i + 1,
               area,
               perimeter);
    }

    for (int i = 0; i < num_circles - 1; i++) {
        for (int j = i + 1; j < num_circles; j++) {
            float distance = sqrt(pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2));
            if (distance <= r[i] + r[j]) {
                printf("\nCircles %d and %d intersect.\n", i + 1, j + 1);
            } else {
                printf("\nCircles %d and %d do not intersect.\n", i + 1, j + 1);
            }
        }
    }

    return 0;
}
