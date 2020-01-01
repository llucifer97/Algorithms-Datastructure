#include <iostream>
#define inf 1e9
using namespace std;

class Edge{
  public:
         int src,dest,weight;
};

class Graph{
  public:
  int v,e;
  Edge *edge;//array of edges
  Graph(int v,int e){
      this->v = v;
      this->e = e;
      edge = new Edge[e];
  }
  
  void addEdge(int u,int v,int w,int count){
      edge[count].src = u;
      edge[count].dest = v;
      edge[count].weight = w; 
  }
  void BellmanFord(int src){
      int distance[v];
      for(int i =0;i<v;i++){
          if(i == src){
              distance[i] = 0;
            } else {
                distance[i] = inf;
            }
      }
      
      //Relaxtion code
      for(int i=1;i<=v-1;i++){
          for(int j=0;j<e;j++){
              int src = edge[j].src;
              int dest = edge[j].dest;
              int wt = edge[j].weight;
              
              //relaxtion check
              if(distance[src] != inf and distance[src] + wt < distance[dest]){
                  distance[dest] = distance[src] +wt;
              }
          }
      }
      
      // check for negative weight cycle
      for(int j=0;j<e;j++){
              int src = edge[j].src;
              int dest = edge[j].dest;
              int wt = edge[j].weight;
              
              //relaxtion check
              if(distance[src] != inf and distance[src] + wt < distance[dest]){
                  cout << "graph has negative cycle";
                  return;
              }
          }
          
          for(int i=0;i<v;i++){
              cout << i <<" - "<<distance[i] << endl;
              //print("%d - %d\n",i,distance[i]);
          }
          
  }
};



int main() {
    int v,e;
    cin >> v >> e;
    Graph g(v,e);
    for(int i = 0;i<e;i++){
        int u,v,w;
        cin >>u>>v>>w;
        g.addEdge(u,v,w,i);
    }
    g.BellmanFord(0);
    
}


5 8
0 1 -1
0 2 4
1 2 3
3 2 5
4 3 -3
1 4 2
1 3 2
3 1 1
