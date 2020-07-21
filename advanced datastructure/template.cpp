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

 // ---------------------------------------
// fast exponentiation

int pow(int a,int n) {
	if(n==0) {
		return 1;
	}

	// check if n is odd
	int subprob = pow(a,n/2);
	if(n&1) {
		return a * subprob * subprob;
	}
}
// ----------------------------------------------------

//// fast mod exponentiation usimng bitmask   ----------------------

ll fastmodexp(ll a ,ll b,ll m) {

	ll res = 1;
	while(b> 0) {
		if(b&1) {
			res = (res*a)%m;
		}

		a = (a*a)%m;
		b = b >> 1;
	}
	return res;
}

// --------------------------------------------------------

int main(){
	 
	return 0;
}
