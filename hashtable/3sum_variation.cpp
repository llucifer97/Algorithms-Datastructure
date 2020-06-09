// C++ program to find three element 
// from different three arrays such 
// that a + b + c is equal to 
// given sum 
https://www.geeksforgeeks.org/find-three-element-from-different-three-arrays-such-that-that-a-b-c-k/

#include<bits/stdc++.h> 
using namespace std; 

// Function to check if there is 
// an element from each array such 
// that sum of the three elements is 
// equal to given sum. 
bool findTriplet(int a1[], int a2[], 
				int a3[], int n1, 
				int n2, int n3, 
				int sum) 
{ 
	// Store elements of 
	// first array in hash 
	unordered_set <int> s; 
	for (int i = 0; i < n1; i++) 
		s.insert(a1[i]); 

	// sum last two arrays 
	// element one by one 
	for (int i = 0; i < n2; i++) 
	{ 
		for (int j = 0; j < n3; j++) 
		{ 
			// Consider current pair and 
			// find if there is an element 
			// in a1[] such that these three 
			// form a required triplet 
			if (s.find(sum - a2[i] - a3[j]) != 
									s.end()) 
				return true; 
		} 
	} 

	return false; 
} 

// Driver Code 
int main() 
{ 
	int a1[] = { 1 , 2 , 3 , 4 , 5 }; 
	int a2[] = { 2 , 3 , 6 , 1 , 2 }; 
	int a3[] = { 3 , 2 , 4 , 5 , 6 }; 
	int sum = 9; 
	int n1 = sizeof(a1) / sizeof(a1[0]); 
	int n2 = sizeof(a2) / sizeof(a2[0]); 
	int n3 = sizeof(a3) / sizeof(a3[0]); 
	findTriplet(a1, a2, a3, n1, n2, n3, sum)? 
	cout << "Yes" : cout << "No"; 

	return 0; 
} 
