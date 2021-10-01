#include <bits/stdc++.h>
using namespace std;


vector<int> adj[1000];
bool vis[1000] = {false};
bool rec[1000] = {false};





bool isCycle(int node,int par)
{
	vis[node] = 1;

   for(int child : adj[node])
   {
      if(vis[child] == 0)
      {
         if(isCycle(child,node) == true)return true;
      }
      else{
         if(child!= par)return true;
      }
   }
   return false;
}




bool isCycledirected(int node)
{
	if(!vis[node])
	{
		vis[node] = true;
		rec[node] = true;

		for(auto & it : adj[node])
		{
			if(!vis[it] && isCycledirected(it))return true;
			else if(rec[it] == true)return true;
		}
	}
	rec[node] = false;
	return false;
}



int main() 
{ 
	int t,u,v;
	cin >> t;
	while(t--)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

// for(int i = 1;i <= 4;i++)
// 	{
// 		if(!vis[i]){
// 			if(isCycledirected(i)){
// 				cout << "it is cyclic!";
// 			}
// 		}
// 	}

	int ans = isCycle(1,-1);
		if(ans) cout << "it is undirected cycle!";
	
	return 0; 
} 
