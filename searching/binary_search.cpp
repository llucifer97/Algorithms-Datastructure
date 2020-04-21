// C++ program to implement recursive Binary Search 
#include <bits/stdc++.h> 
using namespace std; 

// A recursive binary search function. It returns 
// location of x in given array arr[l..r] is present, 
// otherwise -1 
int binarySearch(int arr[], int l, int r, int x) 
{ 
	if (r >= l) { 
		int mid = l + (r - l) / 2; 
		//int  mid = ((unsigned int)l + (unsigned int)r)) >> 1;
		// If the element is present at the middle 
		// itself 
		if (arr[mid] == x) 
			return mid; 

		// If element is smaller than mid, then 
		// it can only be present in left subarray 
		if (arr[mid] > x) 
			return binarySearch(arr, l, mid - 1, x); 

		// Else the element can only be present 
		// in right subarray 
		return binarySearch(arr, mid + 1, r, x); 
	} 

	// We reach here when element is not 
	// present in array 
	return -1; 
} 

int main(void) 
{ 
	int arr[] = { 4,4,4,4,4 }; 
	int x = 4; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int result = binarySearch(arr, 0, n - 1, x); 
	(result == -1) ? cout << "Element is not present in array"
				: cout << "Element is present at index " << result; 
	return 0; 
} 


/*good stuff
 * https://www.quora.com/Whats-an-algorithm-for-finding-the-median-element-in-an-unsorted-array-in-linear-time-constant-space
 * https://hackernoon.com/binary-search-in-detail-914944a1434a
 * https://www.topcoder.com/community/competitive-programming/tutorials/binary-search
 * https://codeforces.com/blog/entry/50041?
 */ 
