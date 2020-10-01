//Merge-sort

//Divide and Conquer algorithm..

//Stable algorithm.....

//Time Complexity is :
//Theta(n*log(n))

//Auxiliary space is:
//O(n).........

//Best suited for Linked list...
//Works in  o(1)............

//used in external sort............

#include<bits/stdc++.h>
using namespace std;

void merge(int *a,int start,int mid,int end)
{
    int n1=mid-start+1;
    int n2=end-mid;
    int temp[n1],temp2[n2];
    for(int i=0;i<n1;i++)
    {
        temp[i]=a[start+i];
    }
    for(int j=0;j<n2;j++)
    {
        temp2[j]=a[mid+j+1];
    }
    int i,j,k=start;
    i=j=0;
    while(i<n1 && j<n2)
    {
        if(temp[i]<=temp2[j])
        {
            a[k]=temp[i];
            i++;
        }
        else
        {
            a[k]=temp2[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
         a[k]=temp[i];
            i++;
            k++;
    }

    while(j<n2)
    {
         a[k]=temp2[j];
            j++;
            k++;
    }
}

void merge_sort(int *a,int start,int end)
{
    if(start < end)
    {
        int mid=start +(end-start)/2;
        merge_sort(a,start,mid);
        merge_sort(a,mid+1,end);
        merge(a,start,mid,end);
    }
}

int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1};
    merge_sort(a,0,9);
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    return 0;
}


