//https://www.interviewbit.com/problems/repeating-subsequence/
//https://www.geeksforgeeks.org/longest-repeating-subsequence/ 
#include <bits/stdc++.h> 
using namespace std; 

int dp[1000][1000]; 

// This function mainly returns LCS(str, str) 
// with a condition that same characters at 
// same index are not considered. 

int findLongestRepeatingSubSeq(string X, int m, int n) 
{ 
	
	if(dp[m][n]!=-1) 
	return dp[m][n]; 
	
	// return if we have reached the end of either string 
	if (m == 0 || n == 0) 
		return dp[m][n] = 0; 

	// if characters at index m and n matches 
	// and index is different 
	if (X[m - 1] == X[n - 1] && m != n) 
		return dp[m][n] = findLongestRepeatingSubSeq(X, 
							m - 1, n - 1) + 1; 

	// else if characters at index m and n don't match 
	return dp[m][n] = max (findLongestRepeatingSubSeq(X, m, n - 1), 
						findLongestRepeatingSubSeq(X, m - 1, n)); 
} 

// Longest Repeated Subsequence Problem 
int main() 
{ 
	string str = "abba"; 
	int m = str.length(); 

memset(dp,-1,sizeof(dp)); 
cout << "The length of the largest subsequence that"
			" repeats itself is : "
		<< findLongestRepeatingSubSeq(str,m,m); 

	return 0; 
// this code is contributed by Kushdeep Mittal 
} 
