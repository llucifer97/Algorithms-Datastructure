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
#define MOD 1000000000

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

ll k;
vector<ll> a,b,c;


vector<vector<ll> > multiply(vector<vector<ll> > A,vector<vector<ll> > B) {


    //lets store the result in some matrix c
    vector<vector<ll> >C(k+1,vector<ll>(k + 1));

    //logic to multiply matrixes
    for(int i =1;i<= k;i++) {
        for(int j =1;j<=k;j++) {
            for(int x = 1;x<=k;x++) {
                C[i][j] =   (C[i][j] + (A[i][x]*B[x][j])%MOD)%MOD;

            }
        }
    }
    return C ;
}

vector<vector<ll> > pow(vector<vector<ll> > A,ll p) {
    //base case

    if(p==1) {
        return A;
    }

    //power is odd
    if(p&1) {
        return multiply(A,pow(A,p-1));
    }

    vector<vector<ll> > X = pow(A,p/2);

    return multiply(X,X);
}






ll compute(ll n) {

    //base case
    if(n==0){
        return 0;
    }

    if(n<=k){
        return b[n-1];
    }
    //otherwise use matrix exponentiation
    vector<ll> F1(k+1);
    //indexing from 1

    //step-1
    for(int i =0;i<=k;i++) {
        F1[i] = b[i-1];
    }

    //step-2 Transformation matrix
    vector<vector<ll> > T(k+1,vector<ll>(k+1));

    for(int i =0;i<= k;i++) {
        for(int j =0;j<=k;j++) {
            if(i<k) {
                //fill 0's and 1's
                if(j== i + 1) {
                    T[i][j] = 1;
                }
                else{
                    T[i][j] = 0;
                }
            }
            else{
                T[i][j] = c[k-j];
            
            }
        }
    }

    // 3 step 
        T = pow(T,n - 1);

    //step - 4
    // Matrix with a vector

    ll res = 0;
    for(int i =0;i<= k;i++) {
        res = (res  +(T[1][i]*F1[i])%MOD)%MOD;
    }
    return res;

} 






int main(){
	ll t,num;

    cin >> t;
    while(t--) {
        cin >> k;

        //init vector F1;
        for(int i =0;i<k;i++){
            cin >> num;
            b.pb(num);

        }

        //coeffiients
        for (int i = 0; i < k; i++)
        {
            cin >> num;
            c.pb(num);
        }
        

    }
	return 0;
}
