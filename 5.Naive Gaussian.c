#include <stdio.h>
#define SIZE 10

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
                A[j][k] = A[j][k] - ratio * A[i][k];
            }

            B[j] = B[j] - ratio * B[i];
        }
    }

    // Back substitution
    X[n - 1] = B[n - 1] / A[n - 1][n - 1];//x3 er value


    // x2 ar x1 er value bahir korar jonno
    for (i = n - 2; i >= 0; i--)
    {
        X[i] = B[i];
        for (j = i + 1; j < n; j++)
        {
            X[i] = X[i] - A[i][j] * X[j];
        }
        X[i] = X[i] / A[i][i];
    }
}

int main()
{
    int i, j, n;
    float A[SIZE][SIZE], B[SIZE], X[SIZE];

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the coefficients of matrix A:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &A[i][j]);
        }
    }

    printf("Enter the constants vector B:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &B[i]);
    }

    gaussianElimination(n, A, B, X);

    printf("\nThe solution is:\n");
    for (i = 0; i < n; i++)
    {
        printf("x%d = %.6f\n", i + 1, X[i]);
    }

    return 0;
}

