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
// int dist[100005] = {INT_MAX};
priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>  >  > pq;


int main(){
    ll w,n,m,u,v;  cin >> n >> m;
    for(int i =0;i<m;i++) {
        cin >> u >> v >> w;
        adj[u].pb(make_pair(v,w));
        adj[v].pb(make_pair(u,w));
    }
    vector<int> dist(n+1,INT_MAX);

    dist[1] = 0;
    pq.push(make_pair(0,1)); // dist,nodeid

    while(!pq.empty()) {

        int curr = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();

        for(pair<int,int> edge : adj[curr]) {
            if(curr_d + edge.second < dist[edge.first]){
                dist[edge.first] = curr_d + edge.second;
                pq.push({dist[edge.first],edge.first});
            }
        }
    }

    for(int i =1;i<=n;i++)cout << dist[i] << " ";



	 
	return 0;
}



/*
6 9
1 2 4
1 6 2
2 3 5
2 6 1
6 3 8
6 5 10
3 4 6
3 5 3
5 4 5


*/