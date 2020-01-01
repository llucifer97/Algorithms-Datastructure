#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<bits/stdc++.h> 
using namespace std;
template<typename T>
class Graph{
map<T,list<T> > adjList;
public:
    Graph(){
    }
    void addEdge(T u, T v,bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
        adjList[v].push_back(u);
        }
        
    }
    //khan's algorithm
    bool isCyclicBFS(T src){
        map<T,int> parent;
        map<T,bool> visited;
        queue<T> q;
        
        q.push(src);
        visited[src] = true;
        parent[src] = src;
        
        while(!q.empty()){
            T node = q.front();
            q.pop();
            
            // iterate over the neighbours of that node laeving parent.
            for(T neighbour: adjList[node]){
                if(visited[neighbour] == true && parent[node] != neighbour){
                    return true;
                }
                else if(!visited[neighbour]){
                    visited[neighbour] = true;
                    parent[neighbour] = node;
                    q.push(neighbour);
                }
                
            }
            
        }
    }
    
    
    
};
int main(){
Graph<int> g;
g.addEdge(1,2);
g.addEdge(1,4);
g.addEdge(4,3);
g.addEdge(2,3);

if(g.isCyclicBFS(1)){
    cout << "cyclic graph";
}
else{
    cout << "non cyclic";
}


return 0;
}
