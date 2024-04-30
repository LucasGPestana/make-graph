#include <stdio.h>
#include <stdlib.h>

int maxValue(int* values, int length) {

    int max_value = 0;

    for (int i = 0; i < length; i++) if (values[i] > max_value) max_value = values[i];

    return max_value;

}

int affine_function(int x) {

    return (4 * x) + 7;

}

int quadratic_function(int x) {
    return (x * x) + (5 * x) + 10;
}

int repeat(char character, int quantity) {
    if (quantity == 0) {

        printf("\n");
        return 0;

    }
    printf("%c", character);
    return repeat(character, quantity - 1);
}

int main()
{
    int x[10];
    int length = sizeof(x) / sizeof(int);
    int y[length];

    for (int i = 0; i < length; i++) x[i] = i + 5;
    for (int i = 0; i < length; i++) y[i] = affine_function(x[i]);

    repeat('-', 60);

    printf("Elementos do dominio (x):\n");
    for (int i = 0; i < length; i++) printf(" %d ", x[i]);
    printf("\n");

    printf("Elementos da imagem (y):\n");
    for (int i = 0; i < length; i++) printf(" %d ", y[i]);

    printf("\n");
    repeat('-', 60);
    printf("\n\n\n");

    int n_rows = maxValue(y, length) + 1;
    int n_cols = maxValue(x, length) + 1;

    if (n_rows < length) n_rows += (length - n_rows);
    if (n_cols < length) n_cols += (length - n_cols);

    char matrix[n_rows][n_cols];

    int k = 0;

    for (int i = 0; i < n_rows; i++) {

        for (int j = 0; j < n_cols; j++) {

                if (i == y[k] && j == x[k]) {

                    matrix[i][j] = '*';
                    k++;

                }
                else matrix[i][j] = ' ';

        }

    }

    for (int i = n_rows - 1; i >= 0; i--) {

        printf("%d ", i);
        for (int j = 0; j < n_cols; j++) {

                printf("\t%c", matrix[i][j]);

        }
        printf("\n");
    }
    printf("  ");
    for (int j = 0; j < n_cols; j++) printf("\t%d", j);

    return 0;
}
