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

// prime sieve-


void prime_sieve(int *p) {

    // first mark all modd prime
    for(int i =3;i<=1000000;i+=2) {
        p[i]  =1;
    }

    //sieve
    for(int i =0;i<=1000000;i += 2) {
        // if the current number is not marksed
        if(p[i] == 1) {
            for(ll j = i*i ;j<= 1000000;j = j + i) {
            p[j] = 0;
        }
     }
        
    }
    //special case
    p[2] = 2;
    p[0] = p[1] = 0;


}



int main(){
	
    int n;
    cin >> n;
    int p[1000005] = {0};
    prime_sieve(p);

    for(int i =0;i<= n;i++) {
        if(p[i] ==1) {
            cout << i << " ";
        }
    }
	return 0;
}
