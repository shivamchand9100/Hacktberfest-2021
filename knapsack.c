#include <stdio.h>
#include <stdlib.h>

typedef struct tm
{
    int weight;
    int profit;
    float pw;
} item;

void swap_item(item *x, item *y)
{
    item temp = *x;
    *x = *y;
    *y = temp;
}

void sort_item_desc(item arr[], int n)
{
    int i, j;
    item key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].pw < key.pw)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

float frac_knapsack(item arr[], int n, int bag)
{
    int i;
    float total_profit = 0;
    sort_item_desc(arr, n);
    for (i = 0; i < n; i++)
    {
        if (bag > 0)
        {
            if (bag > arr[i].weight)
            {
                bag -= arr[i].weight;
                total_profit += arr[i].profit;
                printf("Chose %d\n", i + 1);
            }
            else
            {
                total_profit += arr[i].pw * bag;
                bag = 0;
                printf("Frac chose: item %d frac %f\n", i + 1, arr[i].pw);
            }
        }
        else
        {
            return total_profit;
        }
    }
    return 0;
}

void print_chart(item arr[], int n)
{
    printf("Item\tWeight\tProfit\tP/W\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%0.2f\n", i + 1, arr[i].weight, arr[i].profit, arr[i].pw);
    }
}

int main()
{
    int n, temp, bag;
    printf("Enter number of entries: ");
    scanf("%d", &n);
    item *arr = (item *)calloc(n, sizeof(item));
    printf("Enter n weights in order:\n ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].weight);
    }
    printf("Enter n profits in order:\n ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].profit);
    }
    printf("Enter bag capacity: ");
    scanf("%d", &bag);
    // Calculating p/w:
    for (int i = 0; i < n; i++)
    {
        arr[i].pw = (float)arr[i].profit / (float)arr[i].weight;
    }
    float total_profit = frac_knapsack(arr, n, bag);
    printf("\nThe max profit is: %.2f\n", total_profit);
    printf("\n\n");
    print_chart(arr, n);
    return 0;
}
