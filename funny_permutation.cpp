// B. Funny Permutation
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// A sequence of n numbers is called permutation if it contains all numbers from 1 to n exactly once. For example, the sequences [3,1,4,2], [1] and [2,1] are permutations, but [1,2,1], [0,1] and [1,3,4] are not.

// For a given number n you need to make a permutation p such that two requirements are satisfied at the same time:

// For each element pi, at least one of its neighbors has a value that differs from the value of pi by one. That is, for each element pi (1≤i≤n), at least one of its neighboring elements (standing to the left or right of pi) must be pi+1, or pi−1.
// the permutation must have no fixed points. That is, for every i (1≤i≤n), pi≠i must be satisfied.
// Let's call the permutation that satisfies these requirements funny.

// For example, let n=4. Then [4,3,1,2] is a funny permutation, since:

// to the right of p1=4 is p2=p1−1=4−1=3;
// to the left of p2=3 is p1=p2+1=3+1=4;
// to the right of p3=1 is p4=p3+1=1+1=2;
// to the left of p4=2 is p3=p4−1=2−1=1.
// for all i is pi≠i.
// For a given positive integer n, output any funny permutation of length n, or output -1 if funny permutation of length n does not exist.

// Input
// The first line of input data contains a single integer t (1≤t≤104) — the number of test cases.

// The description of the test cases follows.

// Each test case consists of f single line containing one integer n (2≤n≤2⋅105).

// It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, print on a separate line:

// any funny permutation p of length n;
// or the number -1 if the permutation you are looking for does not exist.
// Example
// inputCopy
// 5
// 4
// 3
// 7
// 5
// 2
// outputCopy
// 3 4 2 1
// -1
// 6 7 4 5 3 2 1
// 5 4 1 2 3
// 2 1
// Note
// The first test case is explained in the problem statement.

// In the second test case, it is not possible to make the required permutation: permutations [1,2,3], [1,3,2], [2,1,3], [3,2,1] have fixed points, and in [2,3,1] and [3,1,2] the first condition is met not for all positions.

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
        if(n==2)
        {
            cout<<"2 1"<<endl;
            continue;
        }
        if(n==3)
        {
            cout<<"-1"<<endl;
            continue;
        }
        if(n%2==0)
        {
            for(int i=n;i>=1;i--)
            {
                cout<<i<<" ";
            }
            cout<<endl;
            continue;
        }
        else
        {
            if(n==5)
            {
                cout<<"5 4 1 2 3"<<endl;
                continue;
            }
            for(int i=n;i>=1;i--)
            {
                if(i==n/2+2)
                {
                    cout<<i-1<<" "<<i<<" ";
                    i--;
                }
                else
                {
                    cout<<i<<" ";
                }
                
            }
            cout<<endl;
            continue;
        }

        

    
    }
    return 0;
}