#include <bits/stdc++.h>
using namespace std;              

#define SZ size()
#define MIN LLONG_MIN
#define MAX LLONG_MAX
#define M 1000000007
#define MP make_pair
#define F first
#define S second
#define endl "\n"
#define sqr(x) ((x)*(x))
#define INF 0x3f3f3f3f

#define pb push_back
#define N 100005
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<char> vc;
typedef vector< vc > vvc;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector< vb > vvb;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef set<pii> spii;
typedef set<int> si;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef map<string, int> msi;
//    vector<vector<int> > vec( n , vector<int> (m, 0)); 
//  memset(a, 0, sizeof(a)); -> a array hai

 vector<pair<int,int> > adj[1000];

void all_pair_shortest_path(int n){

    vvi dist(n+1,vector<int>(n+1,2e9));

    for(int  i = 1;i<=n;i++) {

        dist[i][i] = 0;
        for(pii ed: adj[i]){
            int nb = ed.first;
            int w = ed.second;
            dist[i][nb] = w;
        }
    }

    for(int k = 1;k<=n;k++) {

        for(int i =1;i<=n;i++) {
            for(int j =1;j<=n;j++) {
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
 for(int i =0;i<n;i++){
     cout << dist[i][0] << " ";
 }
}






int main(){
	  ll w,n,m,u,v;  cin >> n >> m;
    for(int i =0;i<m;i++) {
        cin >> u >> v >> w;
        adj[u].pb(make_pair(v,w));
        adj[v].pb(make_pair(u,w));
    }
    all_pair_shortest_path(n);

    
	return 0;
}
