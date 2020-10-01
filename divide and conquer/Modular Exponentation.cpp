#include<bits/stdc++.h>
using namespace std;
int main() {
	long long int t;cin>>t;
	while(t--)
	{
	    long long int x,y,p,res=1;
		cin>>x>>y>>p;
	    if(x==0)
	    cout<<"0\n";
	    else
	    {
	        while(y)
	        {
	            if(y%2!=0)
	            res=(res*x)%p;
	            y=y/2;
	            x=(x*x)%p;
	        }
	        cout<<res<<"\n";
	    }
	}
}
