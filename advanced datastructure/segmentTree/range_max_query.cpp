// CPP code for range maximum query and updates 
#include <bits/stdc++.h> 
using namespace std; 


int getMax(int* st,int ss, int se, int l,int r, int node) 
{ 
	// Check for erroneous input values 
	// if (l < 0 || r > n - 1 || l > r) 
	// { 
	// 	printf("Invalid Input"); 
	// 	return -1; 
	// } 

	if (l <= ss && r >= se) 
		return st[node]; 

	if (se < l || ss > r) 
		return -1; 

	int mid = (ss+ se)/2; 
	
	return max( getMax(st, ss, mid, l, r, 2 * node + 1), getMax(st, mid + 1, se, l, r, 2 * node + 2) ); 
} 

int buildTree(int arr[], int ss, int se,int* st, int si) 
{ 
	if (ss == se) 
	{ 
		st[si] = arr[ss]; 
		return arr[ss]; 
	} 

	int mid = (ss + se)/2; 
	
	st[si] = max(buildTree(arr, ss, mid, st, si * 2 + 1), 
				buildTree(arr, mid + 1, se,st, si * 2 + 2)); 
	
	return st[si]; 
} 


void updateValue(int arr[], int* st, int ss, int se, int index, int value, int node) 
{ 
    if (index < ss || index > se)  
    { 
        cout << "Invalid Input" << endl; 
        return; 
    } 
      
    if (ss == se)  
    {    
        // update value in array and in segment tree 
        arr[index] = value; 
        st[node] = value; 
    } 
    else { 
            int mid = (ss+ se)/2; 
              
            if (index >= ss && index <= mid) 
                updateValue(arr, st, ss, mid, index,  
                            value, 2 * node + 1); 
            else
                updateValue(arr, st, mid + 1, se,  
                            index, value, 2 * node + 2); 
              
            st[node] = max(st[2 * node + 1],  
                       st[2 * node + 2]); 
    } 
    return; 
} 


// Driver code 
int main() 
{ 
	int arr[] = { 1, 3, 5, 7, 9, 11 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

    int* tree = new int[4*n + 1];

	// Build segment tree from given array 
	 buildTree(arr, 0, n - 1, tree, 0); 

	// Print max of values in array 
	// from index 1 to 3 
	cout << "Max of values in given range = "
		<< getMax(tree, 0,n-1, 1, 3,0) << endl; 

    // Update: set arr[1] = 8 and update 
    // corresponding segment tree nodes. 
    updateValue(arr, tree, 0, n - 1, 1, 8, 0); 
  
    // Find max after the value is updated 
    cout << "Updated max of values in given range = " 
         << getMax(tree, 0,n-1, 1, 3,0) << endl;  

	return 0; 
} 
