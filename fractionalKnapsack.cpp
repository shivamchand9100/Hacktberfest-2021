#include<bits/stdc++.h>
using namespace std;
#define INF 1e18
#define MOD 100000007
void solve()
{
    int n = 9;
    int weight[n] = {80,140,70,300,500,250,400,700,350};
    int profit[n] = {2000,2500,1900,4000,6000,3000,7000,6500,3500};
    float ppw[n];
    for(int i=0;i<n;i++)
    {
        ppw[i] = profit[i]/weight[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ppw[j]>ppw[i])
            {
                swap(ppw[i],ppw[j]);
                swap(weight[i],weight[j]);
                swap(profit[i],profit[j]);
            }

        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<profit[i]<<" "<<weight[i]<<" "<<ppw[i]<<"\n";
    }
    cout<<"\n";
    int sum = 0;
    int total = 1000;
    int k = 0;
    float final_profit = 0;
    while(sum<total&&k<n)
    {
        sum+=weight[k];
        
        if(sum>total)
        {
            int f = total - (sum - weight[k]);
            float frac = (float)f/weight[k];
            float p = profit[k]*frac;
            final_profit+=p; 
            break;
        }
        else{
            final_profit+=profit[k];
        }
        k++;
    }
    cout<<sum<<" "<<k<<"\n";
    cout<<final_profit<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}