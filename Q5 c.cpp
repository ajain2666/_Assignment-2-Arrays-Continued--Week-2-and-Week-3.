#include <stdio.h>

int main() {
    int n = 4;
    int A[4][4] = {
        {10, 0, 0, 0},
        {20, 30, 0, 0},
        {40, 50, 60, 0},
        {70, 80, 90, 100}
    };

    int B[10];
    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            B[k++] = A[i][j];
        }
    }

    printf("Stored elements:\n");
    for (int i = 0; i < k; i++)
        printf("%d ", B[i]);

    return 0;
}
