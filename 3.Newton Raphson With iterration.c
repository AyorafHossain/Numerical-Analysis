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

void Newton_Raphson(double Xo,int iter)
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
    while(iter--)
    {
        step++;
        Xr_new = Xr_old - f(Xr_old) / f_prime(Xr_old);  // Newton-Raphson formula
        rel_error = fabs((Xr_new - Xr_old) / Xr_new);  // Relative error

        printf("%d\t %lf\t %lf\n", step, Xr_new, rel_error);

        Xr_old = Xr_new;  // Update old value for the next iteration

    }

    printf("The value of the root is: %lf\n", Xr_new);
}

int main()
{
    double Xo;
    int  iter;
    printf("Enter Xo (Initial Guess) and Iteration: ");
    scanf("%lf %d", &Xo, &iter);

    Newton_Raphson(Xo, iter);  // Call the Newton-Raphson method
    return 0;
}

