#include<bits/stdc++.h>
using namespace std;

class graph
{
    private:
    int n;
    int **c;
    int *cost;
    int *d;
    int *p;
    int stages;
    public:
    graph(int n)
    {
        this->n=n;
        c=new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            c[i]=new int[n+1];
        }
        cost=new int[n+1];
        d=new int[n+1];
        p=new int[n+1];
        for(int i=0;i<=n;i++)
        {
            cost[i]=0;
            d[i]=0;
            p[i]=0;
        }
        stages=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                c[i][j]=0;
            }
        }
    }
    void input()
    {
        cout<<"Enter the cost matrix: "<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>c[i][j];
            }
        }
        cout<<"Enter the number of stages: ";
        cin>>stages;
    }
    void display()
    {
        cout<<"The cost matrix is: "<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void shortest_path()
    {
       for(int i=n-1;i>=1;i--)
       {
            int min=INT_MAX;
            for(int k=i+1;k<=n;k++)
            {
                if(c[i][k]!=0 && c[i][k]+cost[k]<min)
                {
                    min=c[i][k]+cost[k];
                    d[i]=k;
                }
            }
            cost[i]=min;
       }
        p[1]=1;
        p[stages]=n;
        for(int i=2;i<stages;i++)
        {
            p[i]=d[p[i-1]];
        }
    }
    void display_path()
    {
        cout<<"The shortest path is: "<<endl;
        for(int i=1;i<=stages;i++)
        {
            cout<<p[i]<<" ";
        }
    }



};
int main()
{
    int n;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    graph g(n);
    g.input();
    g.display();
    g.shortest_path();
    g.display_path();
    return 0;
}