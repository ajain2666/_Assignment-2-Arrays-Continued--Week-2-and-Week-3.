#include <stdio.h>

int main() {
    int n = 4;
    int A[4][4] = {
        {10, 0, 0, 0},
        {0, 20, 0, 0},
        {0, 0, 30, 0},
        {0, 0, 0, 40}
    };

    int B[4];

    for (int i = 0; i < n; i++) {
        B[i] = A[i][i];
    }

    printf("Stored diagonal elements:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", B[i]);

    return 0;
}
