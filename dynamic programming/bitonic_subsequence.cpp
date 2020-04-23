//Bitonic sequence means which first increse then decrease
//https://www.interviewbit.com/problems/length-of-longest-subsequence/
//solution
#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll dp2[1000];
ll dp[1000];
ll lis(ll arr[],ll n){
	
	ll best = INT_MIN;
	
//	memset(dp,-1,sizeof(dp));
		for(int i = 0;i<n;i++)dp[i] = 1;
	for(int i =1;i<n;i++){
		for(int j = 0;j<i;j++){
			
			if(arr[j]<=arr[i]){
				
				ll curlen = 1 + dp[j];
			dp[i] = max(curlen,dp[i]); 
				}
			}
		best = max(best,dp[i]);
		}
	
	return best;
	
	}

ll lds(ll arr[],ll n){
	
	
	ll best = INT_MIN;
	
//	memset(dp,-1,sizeof(dp));
		for(int i = 0;i<n;i++)dp2[i] = 1;
		
	for(int i =n-1;i>0;i--){
		for(int j = n;j>i;j--){
			
			if(arr[i]>=arr[j]){
				
				ll curlen = 1 + dp2[j];
			dp2[i] = max(curlen,dp2[i]); 
				}
			}
		best = max(best,dp2[i]);
		}
	
	return best;
	
	
	
	
	
	}






int main(){
	ll n;
	cin >> n;
	ll arr[n];
	for(int i =0;i<n;i++)cin >>arr[i];
	
	lis(arr,n);
	lds(arr,n);
	ll ans = 0;
	for(int i =0;i<=n;i++){
		ans = max(ans,dp[i] +dp2[i]);
		
		}
		cout << ans-1;
	
	

return 0;

}























