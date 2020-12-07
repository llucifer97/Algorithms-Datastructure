// https://www.geeksforgeeks.org/finding-minimum-vertex-cover-graph-using-binary-search/


// A C++ program to find size of minimum vertex 
// cover using Binary Search 
#include<bits/stdc++.h> 
#define maxn 25 

using namespace std; 

// Global array to store the graph 
// Note: since the array is global, all the 
// elements are 0 initially 
bool gr[maxn][maxn]; 

// Returns true if there is a possible subset 
// of size 'k' that can be a vertex cover 
bool isCover(int V, int k, int E) 
{ 
	// Set has first 'k' bits high initially 
	int set = (1 << k) - 1; 

	int limit = (1 << V); 

	// to mark the edges covered in each subset 
	// of size 'k' 
	bool vis[maxn][maxn]; 

	while (set < limit) 
	{ 
		// Reset visited array for every subset 
		// of vertices 
		memset(vis, 0, sizeof vis); 

		// set counter for number of edges covered 
		// from this subset of vertices to zero 
		int cnt = 0; 

		// selected vertex cover is the indices 
		// where 'set' has its bit high 
		for (int j = 1, v = 1 ; j < limit ; j = j << 1, v++) 
		{ 
			if (set & j) 
			{ 
				// Mark all edges emerging out of this 
				// vertex visited 
				for (int k = 1 ; k <= V ; k++) 
				{ 
					if (gr[v][k] && !vis[v][k]) 
					{ 
						vis[v][k] = 1; 
						vis[k][v] = 1; 
						cnt++; 
					} 
				} 
			} 
		} 

		// If the current subset covers all the edges 
		if (cnt == E) 
			return true; 

		// Generate previous combination with k bits high 
		// set & -set = (1 << last bit high in set) 
		int c = set & -set; 
		int r = set + c; 
		set = (((r^set) >> 2) / c) | r; 
	} 
	return false; 
} 

// Returns answer to graph stored in gr[][] 
int findMinCover(int n, int m) 
{ 
	// Binary search the answer 
	int left = 1, right = n; 
	while (right > left) 
	{ 
		int mid = (left + right) >> 1; 
		if (isCover(n, mid, m) == false) 
			left = mid + 1; 
		else
			right = mid; 
	} 

	// at the end of while loop both left and 
	// right will be equal,/ as when they are 
	// not, the while loop won't exit the minimum 
	// size vertex cover = left = right 
	return left; 
} 

// Inserts an edge in the graph 
void insertEdge(int u, int v) 
{ 
	gr[u][v] = 1; 
	gr[v][u] = 1; // Undirected graph 
} 

// Driver code 
int main() 
{ 
	/* 
			6 
		/ 
		1 ----- 5 vertex cover = {1, 2} 
		/|\ 
		3 | \ 
		\ | \ 
		2 4 */
	int V = 6, E = 6; 
	insertEdge(1, 2); 
	insertEdge(2, 3); 
	insertEdge(1, 3); 
	insertEdge(1, 4); 
	insertEdge(1, 5); 
	insertEdge(1, 6); 
	cout << "Minimum size of a vertex cover = "
		<< findMinCover(V, E) << endl; 


	// Let us create another graph 
	memset(gr, 0, sizeof gr); 
	/* 
		2 ---- 4 ---- 6 
		/|	 | 
		1 |	 | vertex cover = {2, 3, 4} 
		\ |	 | 
		3 ---- 5 */

	V = 6, E = 7; 
	insertEdge(1, 2); 
	insertEdge(1, 3); 
	insertEdge(2, 3); 
	insertEdge(2, 4); 
	insertEdge(3, 5); 
	insertEdge(4, 5); 
	insertEdge(4, 6); 
	cout << "Minimum size of a vertex cover = "
		<< findMinCover(V, E) << endl; 

	return 0; 
} 
