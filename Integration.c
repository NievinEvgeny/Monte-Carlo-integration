#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* returns pseudo-random number in the [0, 1] */
double getrand()
{
    return (double)rand() / RAND_MAX;
}

double func(double x)
{
    return pow(x, 2);
}

double monte_carlo()
{
    FILE* inside;
    FILE* outside;
    inside = fopen("inside.txt", "w");
    outside = fopen("outside.txt", "w");
    const long int n = 1000000;
    int in = 0;
    for (int i = 0; i < n; i++)
    {
        double x = getrand() * 4;  /* x in [0, 4] */
        double y = getrand() * 16; /* y in [0, 16] */
        if (y <= func(x))
        {
            in++;
            fprintf(inside, "%.2lf %.2lf\n", x, y);
        }
        else
        {
            fprintf(outside, "%.2lf %.2lf\n", x, y);
        }
    }
    return (double)in / n * 64; /* 64 = 4*16 (range of x and y); must be changed if function or ranges are changed*/
}

int main()
{
    FILE* out;
    out = fopen("result.txt", "w");
    double res = monte_carlo();
    fprintf(out, "result = %.6lf", res);
}