#include <bits/stdc++.h>
using namespace std;    
#define N 100005 
#define  pb  push_back       
vector<int> gr[N];
const int M = 22;
int vis[N];
bool odd_cycle = 0;

void dfs(int cur,int par,int col) {
    vis[cur] = col;
    for(auto child : gr[cur]) {
        if(vis[child] == 0) {
            dfs(child,cur,3 - col); // 1 + 2 == 3
        }
    
        else if (child != par && col == vis[child]) {
         odd_cycle  = 1;
        }
    }
    return;
}


void solve() {
    int i,j,k,n,m,ans = 0,cnt = 0,sum = 0;
    cin >> n >> m;
    for(int i =0;i<m;i++) {
        int x,y;
        cin >> x >> y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    dfs(1,0,1);
    if(odd_cycle) {
        cout << "Not bipartite\n";
    }
    else {
        cout << "Bipartite\n";
    }
}


int main(){

solve();


	return 0;
}

/*
5 5
1 2
2 3
3 1
3 4
4 5
*/