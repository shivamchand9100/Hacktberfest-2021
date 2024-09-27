#include<bits/stdc++.h>
using namespace std;
#define INF 1e18
#define MOD 100000007
void solve();

int partition(int a[],int n,int l,int r)
{
    int pivot  = a[r];
    int j = l-1;
    for (int i = l; i < r; i++)
    {
        if(a[i]<=pivot)
        {
            swap(a[j+1],a[i]);
            j++;

        }
        
        
    }
    swap(a[j+1],a[r]);
    return j+1;

}
void print(int a[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    
}
void quicksort(int a[],int n,int l,int r)
{
    if(l<r)
    {
        int mid = l + (r-l)/2;
        int POS_OF_PIVOT = partition(a,n,l,r);
        quicksort(a,n,l,POS_OF_PIVOT-1);
        quicksort(a,n,POS_OF_PIVOT+1,r);

        
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    quicksort(a,n,0,n-1);
    print(a,n);

    
}
/*
lets see what is happening in the entire program
quicksort calls partition function
then inside partition function what we do is epic shit
we compare thee last element that is pivot with the remaining element in the array
initially l is 0 and r is n-1
so int j = l-1;
j = -1;
now in the partition function
lets take the array 5 4 3 2 1
so 5 > 1
nothing happens 
4 > 1
nothing happens 
3 > 1 
nothing happens
2 > 1
nothing happens
finally 
a[-1+1]<-->a[r];

*/