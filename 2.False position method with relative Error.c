#include <stdio.h>
#include <math.h>

double f(double x)
{
    return 3*x-cos(x)-1;//-13-20*x+19*x*x-3*x*x*x
}


void false_position(double Xl, double Xu, double EPSILON)
{
    double Xr_old=0, Xr_new, rel_error;
    int step = 0;

    if (f(Xl) * f(Xu) >= 0)
    {
        printf("The values of a and b are wrong, they must have opposite signs.\n");
        return;
    }

    printf("Step\t Xl\t\t Xu\t\t Xr\t\t f(Xr_new)\t Relative Error\n");

    do
    {
        step++;
        Xr_new = (Xu * f(Xl) - Xl* f(Xu)) / (f(Xl) - f(Xu));
        rel_error = fabs((Xr_new - Xr_old) / Xr_new);


        printf("%d\t %lf\t %lf\t %lf\t %lf\t %lf\n", step, Xl, Xu, Xr_new, f(Xr_new), rel_error);

        Xr_old = Xr_new;

        if (f(Xr_new) * f(Xl) < 0)
            Xu = Xr_new;
        else
            Xl = Xr_new;

    }
    while (rel_error >= EPSILON);

    printf("\n\nThe value of the root is: %lf\n", Xr_new);
}

int main()
{
    double Xl, Xu, EPSILON;

    printf("Enter the value of a, b, and EPSILON:\n");
    scanf("%lf %lf %lf", &Xl, &Xu, &EPSILON);

    false_position(Xl, Xu, EPSILON);

    return 0;
}

