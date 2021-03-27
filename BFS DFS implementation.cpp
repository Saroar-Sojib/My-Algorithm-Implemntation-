#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<int>e[MAX];
bool visited[MAX];
void DFS(int node)
{
    visited[node]=true;
    cout<<node<<' ';
    for(auto x: e[node])
    {
        if(!visited[x])
        {
            DFS(x);
        }
    }
}
void BFS()
{
    queue<int>s;
    s.push(1);
    visited[1]=true;
    while(!s.empty())
    {
        cout<<s.front()<<' ';
        for(auto x:e[s.front()])
        {
            if(!visited[x])
            {
                s.push(x);
                visited[x]=1;
            }
        }
        s.pop();
    }

}
int main()
{
    int n,p;
    cin>>n>>p;
    while(n--)
    {
        int u,v;
        cin>>u>>v;
        e[u].emplace_back(v);
    }
/*
    for(int i=1;i<=p;i++)
    {
        if(!visited[i])
        {
            DFS(i);
        }
    }
    cout<<endl;
    */
    BFS();

}
