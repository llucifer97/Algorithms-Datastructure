
#include <bits/stdc++.h> 
using namespace std; 



int buildTree(int *arr,int *st, int ss, int se, int si) 
{ 
	if (ss == se) 
	{ 
		st[si] = arr[ss]; 
		return arr[ss]; 
	} 

	int mid = (ss + se)/2;
	st[si] = buildTree(arr,st, ss, mid, si*2+1) + 
			buildTree(arr,st, mid+1, se, si*2+2); 
	return st[si]; 
} 


int getSum(int *st, int ss,int se,int qs, int qe,int si) 
{ 
	// Check for erroneous input values 
	// if (qs < 0 || qe > n-1 || qs > qe) 
	// { 
	// 	cout<<"Invalid Input"; 
	// 	return -1; 
	// } 

    if (qs <= ss && qe >= se) 
		return st[si]; 

    if (se < qs || ss > qe) 
		return 0; 

    int mid = (ss + se)/2;
	return getSum(st, ss, mid, qs, qe, 2*si+1) + 
		getSum(st, mid+1, se, qs, qe, 2*si+2);
} 





void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)  
{  
    if (i < ss || i > se)  
        return;  
  
    st[si] = st[si] + diff;  
    if (se != ss)  
    {  
        int mid = (ss + se)/2;  
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);  
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);  
    }  
}  
  
void updateValue(int arr[], int *st, int n, int i, int new_val)  
{  
    // Check for erroneous input index  
    if (i < 0 || i > n-1)  
    {  
        cout<<"Invalid Input";  
        return;  
    }  
  
    // Get the difference between new value and old value  
    int diff = new_val - arr[i];  
    // cout << "difference is:"  << " " << diff << endl;
    // Update the value in array  
    arr[i] = new_val;  
  
    // Update the values of nodes in segment tree  
    updateValueUtil(st, 0, n-1, i, diff, 0);  
}  
  



int main() 
{ 
	int arr[] = {1, 3, 5, 7, 9, 11}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
    int *tree = new int[4*n + 1]; 
	// Build segment tree from given array 

	 buildTree(arr,tree,0,n-1,0); 

	// Print sum of values in array from index 1 to 3 
	cout<<"Sum of values in given range = "<<getSum(tree, 0,n - 1, 1, 3,0)<<endl; 

    updateValue(arr, tree, n, 1, 10);  
  
    // Find sum after the value is updated  
    cout<<"Updated sum of values in given range = "
            <<getSum(tree, 0,n-1, 1, 3,0)<<endl;  

	return 0; 
} 
