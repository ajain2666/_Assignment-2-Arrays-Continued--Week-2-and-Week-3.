#include <stdio.h>

int merge(int a[], int temp[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int count = 0;

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
            count += mid - i + 1;
        }
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = temp[i];

    return count;
}

int mergeSort(int a[], int temp[], int low, int high)
{
    int count = 0;

    if (low < high)
    {
        int mid = (low + high) / 2;

        count += mergeSort(a, temp, low, mid);
        count += mergeSort(a, temp, mid + 1, high);
        count += merge(a, temp, low, mid, high);
    }

    return count;
}

int main()
{
    int a[] = {5, 3, 4, 2, 1};
    int n = 5;
    int temp[5];

    int count = mergeSort(a, temp, 0, n - 1);

    printf("Number of inversions = %d", count);

    return 0;
}

