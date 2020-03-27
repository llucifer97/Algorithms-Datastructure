//strongly connected component in undirected graph

#include <bits/stdc++.h>
using namespace std;              

map<int,list<int> > adjList;

bool visited[99999] = {false};
class Graph{
public:
    Graph(){
    }
    
    void addEdge(int u, int v,bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
        adjList[v].push_back(u);
        }
        
    }
			
		void dfs(int v) {
			visited[v] = true;
			for (int u : adjList[v]) {
				if (!visited[u])
					dfs(u);
			}
			cout << v << "-->";
		}

   
    
    
    
 };
 
 
 
 

int main(){
Graph g;
g.addEdge(1,0,true);
g.addEdge(1,2,true);
g.addEdge(3,4,true);

for(int i =0;i<5;i++){

	if(!visited[i]){
		
		g.dfs(i);
		cout << "\n";
		}
	
	}
return 0;
}
