#include<bits/stdc++.h>
using namespace std;
#define INF 1e18
#define MOD 100000007
void solve();
void merge(int a[],int n,int mid, int l , int r)
{
    // we will form 2 arrays one which contains the elements of a 
    // from l to mid
    // another from mid+1 to r
    // then merge the two array with respect to sorting

    // first find the size of the two arrays and name them as s1 and s2
    int s1 = mid - l + 1; // why here + 1 cause we are includeing the mid value 
    int s2 = r - mid;
    // form 2 arrays
    int left[s1],right[s2];
    //input the values
    for (int i = 0; i < s1; i++)
    {
        left[i] = a[l+i];

    }
    for (int i = 0; i < s2; i++)
    {
        right[i] = a[mid+1+i];
    }
    // now merge into the same array a

    int i = 0;//pointer to the left array

    int j = 0;//pointer to the right array

    int k = l;//pointer to the main array

    while(i<s1&&j<s2)
    {
        if(left[i]<right[j])
        {
            a[k] = left[i];
            i++;
            k++;

        }
        else{
            a[k] = right[j];
            j++;
            k++;
        }
    }
    while(i<s1)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    
    while(j<s2)
    {
        a[k] = right[j];
        j++;
        k++;
    }


}
void mergesort(int a[],int n,int l,int r)
{
    if(l<r)
    {
        int mid  = l + (r - l)/2;
        mergesort(a,n,l,mid);
        mergesort(a,n,mid+1,r);
        merge(a,n,mid,l,r);
    }
}
void print(int a[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergesort(a,n,0,n-1);
    print(a,n);

    return 0;
}
/*
    now before I run the program I want to check what actually is happening 
    we call the function mergesort
    it calls the function mergesotleft
    again mergesort left calls the function mergesortleftleft
    untill l is greater than or equal to r
    so it will go till l is less than r
    merge sort right will happen after that
    lets take an example to understand better
    1 2 3 4 5 6
    mid = 3
    1 2 3 function called with mergesort with l = 0 mid = 2 
    here mid  = 1
    then 1 2 is called 
    here mid = 0
    here function with 1 is called and left  = 0 and right  = 0 = mid
    so since l>=r the function terminates and the function which called this function gets a message that function is terminated
    so in 1 2 mergesort function
    mergesort(mid+1,r)is called which is 1 1 which is 2
    after 2 is called l = r so function again terminates 
    now in 1 2 mergesort function we call the function merge (a,l,r,mid)
    here what is l what is r and what is mid
    l = 0
    r = 1
    mid = 0
    so on calling merge function
    it allocates space to 2 arrays
    mid - l + 1 = 1;
    and r - mid = 1;
    elements in left  = 1
    and elements in right = 2
    now compare while i and j is less than 1 and 1
    both are less than 1 so 1<2 and 1 is inserted kn the original array a 
    now since i == 1
    we come out of the while loop and check is i < 1 i==1 so we dont go inside second for loop 
    next we check if j<1 yes j is less than 1 so we go inside second for loop and then insert the elements in 
    right to the array consecutively
    a[k] = right[j];
    j++;
    k++;
    and continue
    merge is completed now
    we return back to the function 1 2 mergesort
    that function is also completed so it terminates 
    so we go back to the function which called 1 2 that is 1 2 3 mergesort
    the next instruction in here is mergesortright which gives me the value 3 now 
    mergeoperation is performed between 1 2 and 3 
    l = 0;
    r = 2;
    mid = 1
    mid - l + 1;
    r - mid;
    similarly rest will follow ;
    TC = O(nlogn) for any case
    SC = O(n);
    Happy coding:)

*/