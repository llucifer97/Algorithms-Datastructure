// C++ implementation to check whether the array 
// contains a set of contiguous integers
//https://www.geeksforgeeks.org/check-array-contains-contiguous-integers-duplicates-allowed/ 
#include <bits/stdc++.h> 
using namespace std; 

// Function to check whether the array contains 
// a set of contiguous integers 
bool areElementsContiguous(int arr[], int n) 
{ 
	// Storing elements of 'arr[]' in a hash 
	// table 'us' 
	unordered_set<int> us; 
	for (int i = 0; i < n; i++) 
		us.insert(arr[i]); 

	// as arr[0] is present in 'us' 
	int count = 1; 

	// starting with previous smaller element 
	// of arr[0] 
	int curr_ele = arr[0] - 1; 

	// if 'curr_ele' is present in 'us' 
	while (us.find(curr_ele) != us.end()) { 

		// increment count 
		count++; 

		// update 'curr_ele" 
		curr_ele--; 
	} 

	// starting with next greater element 
	// of arr[0] 
	curr_ele = arr[0] + 1; 

	// if 'curr_ele' is present in 'us' 
	while (us.find(curr_ele) != us.end()) { 

		// increment count 
		count++; 

		// update 'curr_ele" 
		curr_ele++; 
	} 

	// returns true if array contains a set of 
	// contiguous integers else returns false 
	return (count == (int)(us.size())); 
} 

// Driver program to test above 
int main() 
{ 
	int arr[] = { 5, 2, 3, 6, 4, 4, 6, 6 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	if (areElementsContiguous(arr, n)) 
		cout << "Yes"; 
	else
		cout << "No"; 

	return 0; 
} 
