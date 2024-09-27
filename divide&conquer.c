#include <stdio.h>
#include <stdlib.h>

int max, min;
int a[100];
void MaxMin(int i, int j)
{
    int max1, min1, mid;
    if (i == j)
    {
        max = min = a[i];
    }
    else
    {
        if (i == j - 1)
        {
            if (a[i] < a[j])
            {
                max = a[j];
                min = a[i];
            }
            else
            {
                max = a[i];
                min = a[j];
            }
        }
        else
        {
            mid = (i + j) / 2;
            MaxMin(i, mid);
            max1 = max;
            min1 = min;
            MaxMin(mid + 1, j);
            if (max < max1)
                max = max1;
            if (min > min1)
                min = min1;
        }
    }
}
int main()
{
    int i, num;
    printf("\nEnter n : ");
    scanf("%d", &num);
    printf("Enter the elements : ");
    for (i = 1; i <= num; i++)
        scanf("%d", &a[i]);

    max = a[0];
    min = a[0];
    MaxMin(1, num);
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
    return 0;
}
