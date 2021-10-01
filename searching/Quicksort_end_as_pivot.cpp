// C++ program to delete element in binary tree 
#include <bits/stdc++.h> 
using namespace std; 

int Partition(int *A,int start,int end)
{
	int pivot = A[end];
	int partitionIndex = start;
	for(int i = start;i<end;i++)
	{
		if(A[i] <= pivot)
		{
			swap(A[i],A[partitionIndex]);
			partitionIndex++;
		}
	}
	swap(A[partitionIndex],A[end]);
	return partitionIndex;
}

void Quicksort(int *A,int start,int end)
{
	if(start < end)
	{
		int partitionIndex = Partition(A,start,end);
		Quicksort(A,start,partitionIndex - 1);
		Quicksort(A,partitionIndex + 1,end);
	}
}



int main()
{
	int A[] = {7,6,5,4,3,2,1,0};
	Quicksort(A,0,7);
	for(int i =0;i<8;i++) cout << A[i] << " ";

	return 0;
}
