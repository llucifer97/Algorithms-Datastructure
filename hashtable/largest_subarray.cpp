/* CPP program to find length of the largest 
subarray which has all contiguous elements */
#include<bits/stdc++.h> 
using namespace std; 

// This function prints all distinct elements 
int findLength(int arr[], int n) 
{ 
	int max_len = 1; // Inialize result 

	// One by one fix the starting points 
	for (int i=0; i<n-1; i++) 
	{ 
		// Create an empty hash set and 
		// add i'th element to it. 
		set<int> myset; 
		myset.insert(arr[i]); 

		// Initialize max and min in 
		// current subarray 
		int mn = arr[i], mx = arr[i]; 

		// One by one fix ending points 
		for (int j=i+1; j<n; j++) 
		{ 
			// If current element is already 
			// in hash set, then this subarray 
			// cannot contain contiguous elements 
			if (myset.find(arr[j]) != myset.end()) 
				break; 

			// Else add current element to hash 
			// set and update min, max if required. 
			myset.insert(arr[j]); 
			mn = min(mn, arr[j]); 
			mx = max(mx, arr[j]); 

			// We have already checked for 
			// duplicates, now check for other 
			// property and update max_len 
			// if needed 
			if (mx - mn == j - i) 
				max_len = max(max_len, mx - mn + 1); 
		} 
	} 
	return max_len; // Return result 
} 

// Driver method to test above method 
int main () 
{ 
	int arr[] = {10, 12, 12, 10, 10, 11, 10}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Length of the longest contiguous"
		<< " subarray is " << findLength(arr, n); 
} 

// This article is contributed by Chhavi 
