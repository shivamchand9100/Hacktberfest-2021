// A. Select Three Sticks
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are given n sticks with positive integral length a1,a2,…,an.

// You can perform the following operation any number of times (possibly zero):

// choose one stick, then either increase or decrease its length by 1. After each operation, all sticks should have positive lengths.
// What is the minimum number of operations that you have to perform such that it is possible to select three of the n sticks and use them without breaking to form an equilateral triangle?

// An equilateral triangle is a triangle where all of its three sides have the same length.

// Input
// The first line of the input contains a single integer t (1≤t≤100) — the number of test cases. The description of the test cases follows.

// The first line of each test case contains a single integer n (3≤n≤300) — the number of sticks.

// The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the lengths of the sticks.

// It is guaranteed that the sum of n over all test cases does not exceed 300.

// Output
// For each test case, print one integer on a single line — the minimum number of operations to be made.

// Example
// inputCopy
// 4
// 3
// 1 2 3
// 4
// 7 3 7 3
// 5
// 3 4 2 1 1
// 8
// 3 1 4 1 5 9 2 6
// outputCopy
// 2
// 4
// 1
// 1
// Note
// In the first test case, you can increase the length of the first stick by 1, then decrease the length of the third stick by 1. In total, you perform 2 operations, such that the three sticks form an equilateral triangle of side length 2.

// In the fourth test case, you can decrease the length of the seventh stick by 1. An equilateral triangle of side length 1 can be selected and formed by the second, fourth, and seventh sticks.


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl

int main()
{

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    int nn;
    cin>>nn;
    while(nn--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int ans=0;
        int minn=INT_MAX;
        for(int i=0;i<n-2;i++)
        {
            ans=abs(v[i+1]-v[i])+abs(v[i+2]-v[i+1]);
            minn=min(minn,ans);
        }



        cout<<minn<<endl;
        


        

    
    }
    return 0;
}