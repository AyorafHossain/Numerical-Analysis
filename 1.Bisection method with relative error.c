#include <stdio.h>
#include <math.h>

double f(double x)
{
    return 3* x -cos(x) -1;
}
//a=lower limit and b=higher limit and c=root
void bisection(double a, double b, double EPSILON)
{
    double c_old=0, c_new, rel_error;
    int step = 0;

    if (f(a) * f(b) >= 0)
    {
        printf("The values of a and b are wrong, they must have opposite signs.\n");
        return;
    }

    printf("Step\t a\t\t b\t\t c\t\t f(c_new)\t\t Relative Error\n");

    do
    {
        step++;
        c_new = (a + b) / 2;//Here a=lower limit b=upper limit and c=root
        rel_error = fabs((c_new - c_old) / c_new);


        printf("%d\t %lf\t %lf\t %lf\t %lf\t %lf\n", step, a, b, c_new, f(c_new), rel_error);

        c_old = c_new;

        if (f(c_new) * f(a) < 0)
            b = c_new;
        else
            a = c_new;

    }
    while (rel_error >= EPSILON);

    printf("The value of the root is: %lf\n", c_new);
}

int main()
{
    double a, b, EPSILON;

    printf("Enter the value of a, b, and EPSILON:\n");
    scanf("%lf %lf %lf", &a, &b, &EPSILON);

    bisection(a, b, EPSILON);

    return 0;
}
