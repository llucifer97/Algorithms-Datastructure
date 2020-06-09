// C++ implementation to find maximum length 
// subsequence with difference between adjacent 
// elements as either 0 or 1 
#include <bits/stdc++.h> 
using namespace std; 

// function to find maximum length subsequence 
// with difference between adjacent elements as 
// either 0 or 1 
int maxLenSub(int arr[], int n) 
{ 
	// hash table to map the array element with the 
	// length of the longest subsequence of which 
	// it is a part of and is the last element of 
	// that subsequence 
	unordered_map<int, int> um; 
	
	// to store the maximum length subsequence 
	int maxLen = 0; 
	
	// traverse the array elements 
	for (int i=0; i<n; i++) 
	{ 
		// initialize current length 
		// for element arr[i] as 0 
		int len = 0; 
		
		// if 'arr[i]-1' is in 'um' and its length of 
		// subsequence is greater than 'len' 
		if (um.find(arr[i]-1) != um.end() && len < um[arr[i]-1]) 
			len = um[arr[i]-1]; 
		
		// if 'arr[i]' is in 'um' and its length of 
		// subsequence is greater than 'len'	 
		if (um.find(arr[i]) != um.end() && len < um[arr[i]]) 
			len = um[arr[i]]; 
			
		// if 'arr[i]+1' is in 'um' and its length of 
		// subsequence is greater than 'len'		 
		if (um.find(arr[i]+1) != um.end() && len < um[arr[i]+1]) 
			len = um[arr[i]+1];	 
		
		// update arr[i] subsequence length in 'um'	 
		um[arr[i]] = len + 1; 
		
		// update maximum length 
		if (maxLen < um[arr[i]])	 
			maxLen = um[arr[i]]; 
	} 
	
	// required maximum length subsequence 
	return maxLen;		 
} 

// Driver program to test above 
int main() 
{ 
	int arr[] = {2, 5, 6, 3, 7, 6, 5, 8}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Maximum length subsequence = "
		<< maxLenSub(arr, n); 
	return 0; 
} 
