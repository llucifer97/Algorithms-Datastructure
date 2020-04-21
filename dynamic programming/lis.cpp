/*
 * approach1: bottom up O(n^2)
 * approach2:   online algorithm        faster method O(nlogn) : https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
 * approach3: using binary indexed tree {O(nlogn)}
 */ 

#include <bits/stdc++.h>
using namespace std;


int lis(int arr[100],int n){
	int dp[100];
	
	
	//base case
	for(int i = 0;i<n;i++)dp[i] = 1;
	
	int best = -1;
	
	for(int i =1;i<n;i++){
		for(int j =0;j<i;j++){
		if(arr[j] <= arr[i]){
			int curlen = 1 + dp[j];
			dp[i] = max(curlen,dp[i]); 
		}
				
		}
		best = max(best,dp[i]);
	}
return best;

}


int main(){
	int arr[100];
	int n;
	cin >> n;
	for(int i = 0;i<n;i++)cin >> arr[i];
	int ans = lis(arr,n);
	cout << ans;

}

/*Related post
 * https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
 * https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n-simple-implementation/?ref=rp
 * https://www.geeksforgeeks.org/longest-increasing-subsequence-using-longest-common-subsequence-algorithm/?ref=rp
 * https://www.geeksforgeeks.org/longest-common-increasing-subsequence-lcs-lis/?ref=rp
 * https://www.geeksforgeeks.org/longest-increasing-odd-even-subsequence/?ref=rp
 * https://www.geeksforgeeks.org/longest-increasing-subsequence-using-bit/?ref=rp
 * https://www.geeksforgeeks.org/construction-of-longest-increasing-subsequence-using-dynamic-programming/
 * https://www.geeksforgeeks.org/longest-increasing-consecutive-subsequence/?ref=rp
 * https://www.geeksforgeeks.org/printing-longest-increasing-consecutive-subsequence/?ref=rp
 * https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/
 * https://www.geeksforgeeks.org/printing-maximum-sum-increasing-subsequence/?ref=rp
 * https://www.geeksforgeeks.org/find-longest-increasing-subsequence-circular-manner/?ref=rp
 * https://www.geeksforgeeks.org/length-of-the-longest-increasing-subsequence-such-that-no-two-adjacent-elements-are-coprime/?ref=rp
 * https://www.geeksforgeeks.org/maximum-product-increasing-subsequence/?ref=rp
 * https://www.geeksforgeeks.org/maximum-product-increasing-subsequence-size-3/?ref=rp
 * https://www.geeksforgeeks.org/increasing-subsequence-of-length-three-with-maximum-product/?ref=rp
 * 
 */ 
