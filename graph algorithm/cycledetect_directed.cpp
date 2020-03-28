#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<bits/stdc++.h> 
using namespace std;
template<typename T>
class Graph{
    int V;
map<T,list<T> > adjList;
public:
    Graph(int v){
        V = v;
    }
    void addEdge(T u, T v,bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
        adjList[v].push_back(u);
        }
        
    }
   
    bool isCyclicHelper(T node,map<T,bool> &visited,map<T,bool> &instack){
        
        visited[node] = true;
        instack[node] = true;
        //Explore the neighbours of the node
        for(T neighbour:adjList[node]){
			//two things can happen
			//the current node is not visied but its further branch is leading to a cycle
            if((!visited[neighbour] && isCyclicHelper(neighbour,visited,instack))||instack[neighbour]){
				return true;
				}
    }
    //going to pop out node
    instack[node] = false;
    return false;
    
   } 
    
    
    bool isCyclic(){
        map<T,bool> visited;
        map<T,bool> instack;
        // you can for finding in every dfs tree
        for(auto i:adjList){
            T node = i.first;
            if(!visited[node]){
                bool cyclePresent = isCyclicHelper(node,visited,instack);
                if(cyclePresent == true){
                    return true;
                }
            }
        }
        return false;
    }
    
};
int main(){
Graph<int> g(4);
g.addEdge(0,2,false);
g.addEdge(0,1,false);
g.addEdge(2 ,3,false);
g.addEdge(2,4,false);
g.addEdge(3,0,false);
g.addEdge(4,5,false);
g.addEdge(1,5,false);
if(g.isCyclic()){
    cout << "cyclic graph";
}
else{
    cout << "non cyclic";
}


return 0;
}
