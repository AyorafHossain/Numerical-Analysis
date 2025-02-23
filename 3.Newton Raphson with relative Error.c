#include <stdio.h>
#include <math.h>

// Equation f(x) = e^(-x) - x
double f(double x)
{
    return exp(-x) - x;
}


// Derivative of f(x), i.e., f'(x) = -e^(-x) - 1
double f_prime(double x)
{
    return -exp(-x) - 1;
}




void Newton_Raphson(double Xo, double Epsilon)
{
    double Xr_old = Xo, Xr_new, rel_error;
    int step = 0;

    // Check if the derivative at the initial guess is zero to avoid division by zero
    if (f_prime(Xr_old) == 0)
    {
        printf("Division by Zero is not allowed.\n");
        return;
    }

    printf("Step\t\t Xi\t\t\t Relative Error\n");

    // Iterative process of Newton-Raphson
    do
    {
        step++;
        Xr_new = Xr_old - f(Xr_old) / f_prime(Xr_old);  // Newton-Raphson formula
        rel_error = fabs((Xr_new - Xr_old) / Xr_new);  // Relative error

        printf("%d\t\t %lf\t\t %lf\n", step, Xr_new, rel_error);

        Xr_old = Xr_new;  // Update old value for the next iteration

    }
    while (rel_error >= Epsilon);    // Repeat until the error is below epsilon

    printf("\n\nThe value of the root is: %lf\n", Xr_new);
}




int main()
{
    double Xo, Epsilon;
    printf("Enter Xo (Initial Guess) and Epsilon (Tolerance): ");
    scanf("%lf %lf", &Xo, &Epsilon);

    Newton_Raphson(Xo, Epsilon);  // Call the Newton-Raphson method
    return 0;
}
