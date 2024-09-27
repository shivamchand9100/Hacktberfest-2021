#include<bits/stdc++.h>
using namespace std;

void addEdge(int u,int v,vector<int>adjlist[])
{
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
}

vector<int> BfsOfGraph(int N,vector<int>adjlist[])
{
    vector<int>bfs;
    vector<int>vis(N+1,0);
    
    for(int i=1;i<=N;i++)
    {
        if(!vis[i])//vis[i]==0
        {
            queue<int>q;
            q.push(i);
            vis[i]=1;

            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for(auto it:adjlist[node])
                {
                    if(!vis[it])
                    {
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }

        }
    }

    return bfs;
}
void PrintGraph(int N, vector<int>adjlist[])
{
    for (int i = 1; i <= N; i++)
    {
        cout<<"Node "<<i<<"->";
        for(auto it : adjlist[i])
        {
            cout<<it<<"->";
        }
        cout<<"\n";
    }
    
}
int main()
{
    int N;

    cout<<"Enter the no. of nodes of a graph:";
    cin>>N;

    int E;
    cout<<"Enter the no. of Edges:\n";
    cin>>E;
    vector<int>AdjList[N+1];
    cout<<"Enter the edges:\n";
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(u,v,AdjList);
    }

    PrintGraph(N,AdjList);

    vector<int>ans=BfsOfGraph(N,AdjList);
    for(auto it : ans)
    {
        cout<<it<<" ";

    }
    return 0;

}