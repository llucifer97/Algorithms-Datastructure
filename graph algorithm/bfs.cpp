#include <iostream>
#include <map>
#include <list> 
#include <queue> 
using namespace std;

template<typename T>

	class Graph{
	    map<T,list<T>> adjlist;
	public:
	        Graph(){
	            
	        }
	    void addEdge(T u,T v,bool bidir = false){
	        adjlist[u].push_back(v);
	        if(bidir == false){
	            adjlist[v].push_back(u);
	        }
	    }
	    
	    void printGraph(){
	        for(auto i:adjlist){
	            cout << i.first << "->";
	            
	            for(auto entry: i.second)
	            {
	            cout << entry << " ";
	            }
	            cout << endl;
	        }
	   }
	   
	   void BFS(T src){
	       queue<T> q;
	       map<T,bool> visited;
	       q.push(src);
	       visited[src] = true;
	       
	       while(!q.empty()){
	           T node = q.front();
	           cout << node << " ";
	           q.pop();
	           
	           //find the nodes not visited
	           
	           for(int neighbour : adjlist[node]){
	               if(!visited[neighbour]){
	                   q.push(neighbour);
	                   visited[neighbour] = true;
	               }
	           }
	       }
	       
	       
	   }
	    
	    
	};
	




int main() {
    
    Graph<int> g;
    g.addEdge(0,1);
g.addEdge(1,2);
g.addEdge(0,4);
g.addEdge(2,4);
g.addEdge(2,3);
g.addEdge(3,4);
g.addEdge(3,5);
g.BFS(0);
    
	
	
	g.printGraph();
	
	
	
	
	
	
	return 0;
}
