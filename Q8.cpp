#include <stdio.h>

int main()
{
    int a[100], n, i, j, count = 0;
    int found;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i++)
    {
        found = 0;

        for (j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                found = 1;
                break;
            }
        }

        if (found == 0)
            count++;
    }

    printf("Total number of distinct elements = %d", count);

    return 0;
}


