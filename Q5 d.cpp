#include <stdio.h>

int main() {
    int n = 4;
    int A[4][4] = {
        {10, 20, 30, 40},
        {0, 50, 60, 70},
        {0, 0, 80, 90},
        {0, 0, 0, 100}
    };

    int B[10];
    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            B[k++] = A[i][j];
        }
    }

    printf("Stored elements:\n");
    for (int i = 0; i < k; i++)
        printf("%d ", B[i]);

    return 0;
}
