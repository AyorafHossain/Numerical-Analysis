#include <stdio.h>
#include <math.h>

#define SIZE 20

// Gaussian Elimination Function
void gaussianElimination(int n, float A[SIZE][SIZE], float B[SIZE], float X[SIZE])
{
    int i, j, k;
    float ratio;

    // Forward elimination
    for (i = 0; i < n - 1; i++)
    {
        if (A[i][i] == 0.0)
        {
            printf("Mathematical Error: Division by zero.\n");
            return;
        }

        for (j = i + 1; j < n; j++)
        {
            ratio = A[j][i] / A[i][i];
            for (k = i; k < n; k++)
            {
                A[j][k] -= ratio * A[i][k];
            }
            B[j] -= ratio * B[i];
        }
    }

    // Back substitution
    X[n - 1] = B[n - 1] / A[n - 1][n - 1];

    for (i = n - 2; i >= 0; i--)
    {
        X[i] = B[i];
        for (j = i + 1; j < n; j++)
        {
            X[i] -= A[i][j] * X[j];
        }
        X[i] /= A[i][i];
    }
}

// Main Program: Direct Polynomial Interpolation
int main()
{
    int totalPoints, n, i, j;
    float x[SIZE], y[SIZE], xp;
    float A[SIZE][SIZE], B[SIZE], coeff[SIZE];

    printf("Enter total number of data points: ");
    scanf("%d", &totalPoints);

    printf("Enter x values:\n");
    for (i = 0; i < totalPoints; i++)
        scanf("%f", &x[i]);

    printf("Enter corresponding y values:\n");
    for (i = 0; i < totalPoints; i++)
        scanf("%f", &y[i]);

    printf("Enter degree of interpolating polynomial: ");
    scanf("%d", &n);

    if (n >= totalPoints)
    {
        printf("Polynomial degree must be less than number of data points.\n");
        return 1;
    }

    printf("Enter value of x to interpolate: ");
    scanf("%f", &xp);

    // Step 1: Choose (n+1) nearest points
    int closest = 0;
    float minDiff = fabs(xp - x[0]);
    for (i = 1; i < totalPoints; i++)
    {
        if (fabs(xp - x[i]) < minDiff)
        {
            minDiff = fabs(xp - x[i]);
            closest = i;
        }
    }

    int start = closest - n / 2;
    if (start < 0)
    {
        start = 0;
    }

    if (start + n >= totalPoints)
    {
        start = totalPoints - n - 1;
    }



    // Step 2: Create Vandermonde matrix A and vector B
    for (i = 0; i <= n; i++)
    {
        float xi = x[start + i];
        B[i] = y[start + i];
        for (j = 0; j <= n; j++)
        {
            A[i][j] = pow(xi, j);
        }
    }

    // Step 3: Solve the system A * coeff = B
    gaussianElimination(n + 1, A, B, coeff);

    // Step 4: Interpolate at xp
    float yp = 0;
    for (i = 0; i <= n; i++)
    {
        yp += coeff[i] * pow(xp, i);
    }

    // Output
    printf("\nThe interpolating polynomial coefficients are:\n");
    for (i = 0; i <= n; i++)
    {
        printf("a%d = %.6f\n", i, coeff[i]);
    }

    printf("\nInterpolated value at x = %.6f is: %.6f\n", xp, yp);

    return 0;
}
