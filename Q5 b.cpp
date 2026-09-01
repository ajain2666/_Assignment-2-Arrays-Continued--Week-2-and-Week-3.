#include <stdio.h>

int main() {
    int n = 4;
    int A[4][4] = {
        {10, 20, 0, 0},
        {30, 40, 50, 0},
        {0, 60, 70, 80},
        {0, 0, 90, 100}
    };

    int B[3 * 4 - 2];
    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i - j >= -1 && i - j <= 1) {
                B[k++] = A[i][j];
            }
        }
    }

    printf("Stored elements:\n");
    for (int i = 0; i < k; i++)
        printf("%d ", B[i]);

    return 0;
}
