// C++ implementation of longest continuous increasing 
// subsequence 
#include <bits/stdc++.h> 
using namespace std; 

// Function for LIS 
int findLIS(int A[], int n) 
{ 
	unordered_map<int, int> hash; 

	// Initialize result 
	int LIS_size = 1; 
	int LIS_index = 0; 

	hash[A[0]] = 1; 

	// iterate through array and find 
	// end index of LIS and its Size 
	for (int i = 1; i < n; i++) { 
		hash[A[i]] = hash[A[i] - 1] + 1; 
		if (LIS_size < hash[A[i]]) { 
			LIS_size = hash[A[i]]; 
			LIS_index = A[i]; 
		} 
	} 

	// print LIS size 
	cout << "LIS_size = " << LIS_size << "\n"; 

	// print LIS after setting start element 
	cout << "LIS : "; 
	int start = LIS_index - LIS_size + 1; 
	while (start <= LIS_index) { 
		cout << start << " "; 
		start++; 
	} 
} 

// driver 
int main() 
{ 
	int A[] = { 2, 5, 3, 7, 4, 8, 5, 13, 6 }; 
	int n = sizeof(A) / sizeof(A[0]); 
	findLIS(A, n); 
	return 0; 
} 
