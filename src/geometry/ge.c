#include <libgeometry/ge_calc.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_CIRCLES 10

void get_input(char* input, int max_len)
{
    printf("Enter the circle parameters in format circle(x y,r): ");
    fgets(input, max_len, stdin);
}

bool check_intersection(struct Circle circle1, struct Circle circle2)
{
    float distance = sqrt(
            pow((circle1.x - circle2.x), 2) + pow((circle1.y - circle2.y), 2));
    return distance <= circle1.r + circle2.r;
}

int main(int argc, const char** argv)
{
    int num_circles;
    printf("Enter the number of circles (1-10): ");
    scanf("%d", &num_circles);
    getchar();
    if (num_circles <= 0) {
        printf("Error. Enter a number between 1 and 10.\n");
        return 1;
    }

    struct Circle circles[MAX_CIRCLES];

    char input[MAX_CIRCLES][MAX_INPUT_LENGTH];

    for (int i = 0; i < num_circles; i++) {
        get_input(input[i], MAX_INPUT_LENGTH);
    }

    int parse_result = parser(num_circles, input, circles);
    if (parse_result != 0) {
        return 1;
    }

    for (int i = 0; i < num_circles; i++) {
        float s_circle = circle_area(circles[i].r);
        printf("\nCircle %d area: %f\n", i + 1, s_circle);

        float p_circle = circle_perimeter(circles[i].r);
        printf("Circle %d perimeter: %f\n", i + 1, p_circle);
    }

    for (int i = 0; i < num_circles - 1; i++) {
        for (int j = i + 1; j < num_circles; j++) {
            if (check_intersection(circles[i], circles[j])) {
                printf("\nCircle %d and Circle %d intersect\n", i + 1, j + 1);
            } else {
                printf("\nCircle %d and Circle %d do not intersect\n",
                       i + 1,
                       j + 1);
            }
        }
    }

    return 0;
}