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

int x,y,GCD;
void Extendedeuclidean(int a,int b) {
    //base case
    if(b==0) {
        x = 1;
        y = 0;
        GCD = a;
        return;
    }

//recursive case
Extendedeuclidean(b,a%b);
int cX = y;
int cY = x - (a/b)*y;


x = cX;
y = cY;
// cout << x << "  " << y << endl;

}
// to find multiplicative modulo inverse assuming that it exists
int inversmodulo(int a,int m) {
    Extendedeuclidean(a,m);
    return (x+m)%m;
}


int main(){
	
    //Extendedeuclidean(18,30);
    cout << inversmodulo(6,7);
  //  cout << x << " " << y;
	return 0;
}
