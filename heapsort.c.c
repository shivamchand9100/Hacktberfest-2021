#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void display(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int *create(int n)
{
    int *a = (int *)malloc(n * sizeof(int));
    a[0] = 0;
    for (int i = 1; i < n; i++)
        a[i] = rand() % 100 + 1;
    return a;
}
void heapify(int *a, int i, int n)
{
    int l = 2 * i, r = 2 * i + 1, largest = i;
    if (l < n && a[l] > a[largest])
    {
        largest = l;
    }
    if (r < n && a[r] > a[largest])
    {
        largest = r;
    }
    if (largest == i)
    {
        return;
    }
    else
    {
        swap(&a[i], &a[largest]);
        heapify(a, largest, n);
    }
}
void build_heap(int *a, int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(a, i, n);
    }
}
void heapsort(int *a, int n)
{
    build_heap(a, n);
    for (int i = n - 1; i > 1; i--)
    {
        swap(&a[i], &a[1]);
        n--;
        heapify(a, 1, n);
    }
}
void b_sort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            if (a[j] < a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}
double f5(int *a, int n)
{
    double timetaken;
    clock_t t;
    t = clock();
    heapsort(a, n);
    t = clock() - t;
    timetaken = (double)t / CLOCKS_PER_SEC;
    return timetaken;
}
double f6(int *a, int n)
{
    double timetaken;
    heapsort(a, n);
    clock_t t;
    t = clock();
    heapsort(a, n);
    t = clock() - t;
    timetaken = (double)t / CLOCKS_PER_SEC;
    return timetaken;
}
double f7(int *a, int n)
{
    double timetaken;
    b_sort(a, n);
    clock_t t;
    t = clock();
    heapsort(a, n);
    t = clock() - t;
    timetaken = (double)t / CLOCKS_PER_SEC;
    return timetaken;
}
void f8(int n)
{
    n++;
    int *a = create(n);
    double t1, t2, t3;
    t1 = f5(a, n);
    t2 = f6(a, n);
    t3 = f7(a, n);
    printf("%f\t%f\t%f\n", t1, t2, t3);
}
int largest(int *a, int n)
{
    int max = a[1];
    for (int i = 2; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}
void replace(int *a, int i, int key, int n)
{
    display(a, n);
    a[i] = key;
    build_heap(a, n);
    display(a, n);
}
void insert(int *a, int key, int n)
{
    int s = n + 1, i = n;
    display(a, n);
    a[n] = key;
    while (key > a[i / 2] && i > 1)
    {
        a[i] = a[i / 2];
        i = i / 2;
    }
    a[i] = key;
    display(a, s);
}
void delete (int *a, int n)
{
    swap(&a[1], &a[n - 1]);
    heapify(a, 1, n - 1);
}
int main()
{
    int n, *a, ch = 0;
    printf("0.Quit\n");
    printf("1.N random Array\n");
    printf("2.Display the array\n");
    printf("3.Sort the array using heap sort(ascending)\n");
    printf("4.Sort the array in descending order\n");
    printf("5.Time complexity to sort in ascending order given array is in random order\n");
    printf("6.Time complexity to sort in ascending order given array is in ascending order\n");
    printf("7.Time complexity to sort in ascending order given array is in descending order\n");
    printf("8.Time compleity to sort ascending all cases in tabular format\n");
    printf("9.Extract the largest element\n");
    printf("10.Replace value at a node with new value\n");
    printf("11.Insert new element\n");
    printf("12.Delete an element\n");
    do
    {
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            break;
        case 1:
            printf("Enter n:");
            scanf("%d", &n);
            n++;
            a = create(n);
            break;
        case 2:
            display(a, n);
            break;
        case 3:
            heapsort(a, n);
            display(a, n);
            break;
        case 4:
            b_sort(a, n);
            display(a, n);
            break;
        case 5:
            printf("Time taken %f\n", f5(a, n));
            break;
        case 6:
            printf("Time taken %f\n", f6(a, n));
            break;
        case 7:
            printf("Time taken %f\n", f7(a, n));
            break;
        case 8:
            printf("Random\tAscending\tDescending\n");
            for (int i = 5000; i <= 50000; i += 5000)
            {
                f8(i);
            }
            break;
        case 9:
            printf("Largest is:%d\n", largest(a, n));
            break;
        case 10:
            printf("Enter index and key:");
            {
                int i, key;
                scanf("%d%d", &i, &key);
                replace(a, i, key, n);
            }
            break;
        case 11:
            printf("Enter element:");
            {
                int x;
                scanf("%d", &x);
                insert(a, x, n);
                n++;
            }
            break;
        case 12:
            delete (a, n);
            n--;
            display(a, n);
        default:
            break;
        }
    } while (ch != 0);
    free(a);
    return 0;
}