#include<bits/stdc++.h>
using namespace std;

vector<int>graph[10005];
vector<int>revgraph[10005];
stack<int> s;
bool mrk[10005];
void dfs(int src)
{
    mrk[src] = true;
    for(int i = 0 ; i < graph[src].size() ;i++)
    {
        if(!mrk[graph[src][i]])
        {
            dfs(graph[src][i]);
        }
    }
    s.push(src);
}
void dfs2(int src)
{
mrk[src] = true;
cout<<src<<"-";
for(int i = 0 ; i< revgraph[src].size(); i++)
{
    if(!mrk[revgraph[src][i]])
    {
        dfs2(revgraph[src][i]);
    }
}
}
int main()
{
    int v;
    cin >> v;
    int e;
    cin >> e;
    int x,y;
    int i,j;
    for(i = 0 ; i < e ; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        revgraph[y].push_back(x);
    }
    for(i = 0 ; i < v; i++)
    {
        mrk[i] = false;
    }
    for(i = 0 ; i < v; i++)
    {
        if(!mrk[i])
        {
            dfs(i);
        }
    }
    //NOW reversing graph's dfs;
    for(i = 0 ; i < v ; i++)
    {
        mrk[i] = false;
    }
    cout<<"CONNECTED COMPONENTS ARE\n";
    while(!s.empty())
    {
        int tmp = s.top();
        s.pop();
        if(!mrk[tmp])
        {
            dfs2(tmp);
            cout<<endl;
        }
    }

    return 0;
}
