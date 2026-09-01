#include <stdio.h>

int main() {
    int n = 3;

    int A[3][3] = {
        {10, 20, 30},
        {20, 40, 50},
        {30, 50, 60}
    };

    int B[6];
    int k = 0;

    // Store only lower triangular part
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

