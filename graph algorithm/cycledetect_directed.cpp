#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<bits/stdc++.h> 
using namespace std;

    int V;
map<int,list<int> > adjList;

    void addEdge(int u, int v,bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
        adjList[v].push_back(u);
        }
        
    }
   
    bool isCyclicHelper(int node,map<int,bool> &visited,map<int,bool> &instack){
        
        visited[node] = true;
        instack[node] = true;
        //Explore the neighbours of the node
        for(int neighbour:adjList[node]){
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
        map<int,bool> visited;
        map<int,bool> instack;
        // you can for finding in every dfs tree
        for(auto i:adjList){
            int node = i.first;
            if(!visited[node]){
                bool cyclePresent = isCyclicHelper(node,visited,instack);
                if(cyclePresent == true){
                    return true;
                }
            }
        }
        return false;
    }
    

int main(){
addEdge(0,2,false);
addEdge(0,1,false);
addEdge(2 ,3,false);
addEdge(2,4,false);
addEdge(3,0,false);
addEdge(4,5,false);
addEdge(1,5,false);
if(isCyclic()){
    cout << "cyclic graph";
}
else{
    cout << "non cyclic";
}


return 0;
}
