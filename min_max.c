#include <stdio.h>

struct pair
{
    int min;
    int max;
};

struct pair getMinMax(int arr[], int l, int h)
{
    struct pair minmax, fst, sec;
    if (l == h)
    {
        minmax.max = arr[l];
        minmax.min = arr[l];
        return minmax;
    }
    if (h == l + 1)
    {
            if (arr[l] > arr[h])
            {
                minmax.max = arr[l];
                minmax.min = arr[h];
            }
            else
            {
                minmax.max = arr[h];
                minmax.min = arr[l];
            }
            return minmax;
        }
    
    else
    {
        int mid;
        mid = (l + h) / 2;
        fst = getMinMax(arr, l, mid);
        sec = getMinMax(arr, mid + 1, h);

        if (fst.min < sec.min)
            minmax.min = fst.min;
        else
            minmax.min = sec.min;

        if (fst.max > sec.max)
            minmax.max = fst.max;
        else
            minmax.max = sec.max;
        return minmax;
    }
}
int main()
{
    int n;
    printf("Enter no. of elements - ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements -");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    struct pair minmax = getMinMax(arr, 0, n - 1);
    printf("\nMinimum element is %d", minmax.min);
    printf("\nMaximum element is %d", minmax.max);
    getchar();
}