#include <stdio.h>
#include <math.h>

double f(double x)
{
    return 3*x - cos(x)-1;
}

void bisection(double a, double b,int iteration)
{
    double c_old=0, c_new, rel_error;
    int step = 0;


    if (f(a) * f(b) >= 0)
    {
        printf("The values of a and b are wrong\n");
        return;
    }

    printf("Step\t a\t\t b\t\t c\t\t f(c_new)\t Relative Error\n");


    while (iteration--)
    {
        step++;
        c_new = (a + b) / 2;
        rel_error = fabs((c_new - c_old) / c_new);
        printf("%d\t %lf\t %lf\t %lf\t %lf\t %lf\n", step, a, b, c_new, f(c_new), rel_error);
        c_old = c_new;

        if (f(c_new) == 0.0)
            break;

        else if (f(c_new) * f(a) < 0)
            b = c_new;
        else
            a = c_new;
    }

    printf("\n\nThe value of the root is: %lf\n", c_new);
}

int main()
{
    double a, b;
    int iteration;


    printf("Enter the value of a, b, and iteration:\n");
    scanf("%lf %lf %d", &a, &b, &iteration);

    bisection(a, b,iteration);

    return 0;
}


