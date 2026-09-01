#include <stdio.h>

int findMissingBinary(int arr[], int n) {
    int low = 0;
    int high = n - 2;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == mid + 1) {
            // Missing number is on the right
            low = mid + 1;
        } else {
            // Missing number is on the left
            high = mid - 1;
        }
    }

    return low + 1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7};
    int n = 7;

    printf("Missing number = %d\n", findMissingBinary(arr, n));

    return 0;
}
