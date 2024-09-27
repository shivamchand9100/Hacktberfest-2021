#include <stdio.h>

struct item
{
    double value;
    double weight;
    double ratio;
} ;

int main()
{
    double cap = 0, tot_profit = 0;
    int n;
    printf("Enter the Knapsack capacity- ");
    scanf("%lf", &cap);
    printf("Enter number of items- ");
    scanf("%d", &n);
    item items[n];
    printf("Enter %d values and weights:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &items[i].value, &items[i].weight);
    }

    for (int i = 0; i < n; i++)
    {
        items[i].ratio = items[i].value / items[i].weight;
    }
 item temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
    int i = 0;
    while (i < n)
    {
        if (items[i].weight > cap)
            break;
        tot_profit += items[i].value;
        cap -= items[i].weight;
        i++;
    }

    if (i != n && cap > 0)
    {
        tot_profit += items[i].ratio * cap;
    }

    printf("Total profit = %lf\n", tot_profit);
}
