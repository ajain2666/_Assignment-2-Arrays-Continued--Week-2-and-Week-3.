#include <stdio.h>

int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1)
            return i + 1;
    }

    return n;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7};
    int n = 7;

    printf("Missing number = %d\n", findMissingLinear(arr, n));

    return 0;
}
