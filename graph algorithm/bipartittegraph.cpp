#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<bits/stdc++.h> 
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
     }
   
   
   bool isBipartite(int s){
       queue<int> q;
       q.push(s);
       
       int *colors = new int[V];
       for(int i =0;i<V;i++){
           colors[i] = -1;//not visited
       }
       
       colors[s] = 0;
       bool ans = true;
       
       while(!q.empty()&&ans){
           int u = q.front();
           q.pop();
           
           for(auto v:l[u]){
               if(colors[v] == -1){
                   colors[v] = 1 - colors[u];
                   q.push(v);
               }
                else if(colors[v] == colors[u]){
                    return false;
                    
                }
               
           }
           
       }
       return true;
   }
    
    // second implementation~codencode
    /*
bool dfs(int v,int c)
{
    vis[v] = 1;
    col[v] = c;

    for(int child : ar[v])
    {
        if(vis[child] == 0)
        {
            if(dfs(child,c^1) == false)
                return false;
        }
        else{
            if(col[v] == col[=child])
                return false;
        }
    }
    return true;
}
*/
    
};
int main(){
Graph g(4);
g.addEdge(0,1);
g.addEdge(2,0);
g.addEdge(1,3);
g.addEdge(2,3);
g.addEdge(0,3);
if(g.isBipartite(0)){
    cout << "yes it is";
}
else{
    cout << "no it is not";
}


return 0;
}
