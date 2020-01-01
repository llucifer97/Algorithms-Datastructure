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
    void dfsHelper(T node,map<T,bool> &visited,list<T> &ordering){
        visited[node] = true;
        
        //will call dfs on the unvisited neighbours of the current node
        for(T neighbour:adjList[node]){
            if(!visited[neighbour]){
                dfsHelper(neighbour,visited,ordering);
            }
        }
        // Add 1 line for dfsTopologicalSort
        // At this point ,all the children of current node have been visited
        // so we can add current node to the list
        ordering.push_front(node);
        
    }
    
    void dfsTopologicalSort(){
        map<T,bool> visited;
        list<T> ordering;
        
        for(auto i:adjList){
            //i is pair (node ,list of nodes)
            T node = i.first;
            if(!visited){
                dfsHelper(node,visited,ordering);
            }
            
        }
        
        for(T element:ordering){
            cout << element << "-->";
        }
    }
    
    
    
    
    
};
int main(){
Graph<string> g;
g.addEdge("English","ProgrammingLogic",false);
g.addEdge("Maths","Programming Logic",false);
g.addEdge("Programming Logic","HTML",false);
g.addEdge("Programming Logic","Python",false);
g.addEdge("Programming Logic","Java",false);
g.addEdge("Programming Logic","JS",false);
g.addEdge("Python","WebDev",false);
g.addEdge("HTML","CSS",false);
g.addEdge("CSS","JS",false);
g.addEdge("JS","WebDev",false);
g.addEdge("Java","WebDev",false);
g.addEdge("Python","WebDev",false);
g.dfsTopologicalSort();
return 0;
}
