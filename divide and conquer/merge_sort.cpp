//Merge Sort
#include<bits/stdc++.h> 
using namespace std;


void merge(int A[],int l,int m,int r){
	int i=l,j=m+1,k=l;
	int B[100];
	while(i<=m && j<=r)
	{
		if(A[i]<A[j])
			B[k++]=A[i++];
		else
			B[k++]=A[j++];
		}
	for(;i<=m;i++)
		B[k++]=A[i];
	for(;j<=r;j++)
		B[k++]=A[j];
	for(i=l;i<=r;i++)
		A[i]=B[i];
	
	
	
	
	}


void mergeSort(int arr[],int l,int r){
	
	if(l<r){
		
		int m = l + (r-l)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	
		}
		
		
	
	}





int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    //printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    //printArray(arr, arr_size); 
    return 0; 


}















