#include <iostream>
#include <algorithm>
using namespace std;
bool ispossiblesolution(int mid, int arr[], int n, int target)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int diff = 0;
        if (arr[i] > mid)
        
            diff = arr[i] - mid;
            sum = sum + diff;
    }  
        if (sum >= target)
        {
            return true;
        }
        else
            return false;
    

}

int getmaxheightofsaw(int arr[], int n, int target)
{
    sort(arr, arr + n);
    int s = 0;
    int e = arr[n - 1];

    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (ispossiblesolution(mid, arr, n, target))
        {
            // store answer
            ans = mid;
            // move right
            s = mid + 1;
        }
        else
        {
            // move left
            e = mid - 1;
        }
    }
    return ans;
}
int main()
{

    int arr[] = {20,15,10,17};
    int target = 7;

    int ans = getmaxheightofsaw(arr, 4, target);
    cout << "answer is " << ans << endl;
    return 0;
}

Input:
size= 4 target =7
20 15 10 17

Output:
15

