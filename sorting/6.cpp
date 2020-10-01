#include<bits/stdc++.h>
using namespace std;

//Method 1

//Naive partition..........
//Time Complexity is O(n).......
//Auxiliary Space is O(n)......

void partition(int *a,int l,int h,int p)
{
    int temp[h-l+1];
    int index=0;
    for(int i=l;i<=h;i++)
    {
        if(a[i] <=a[p])
        {
            temp[index]=a[i];
            index++;
        }
    }
    for(int i=l;i<=h;i++)
    {
        if(a[i]>a[p])
        {
            temp[index]=a[i];
            index++;
        }
    }
    for(int i=l;i<=h;i++)
    {
        a[i]=temp[i-l];
        cout << a[i] <<" ";
    }
}

//Method 2........
//Time Complexity is O(n)...
//Auxiliary space is o(1)...........
//Lomuto Partition.......
// We assumed the pivot element is the last-element................

int partition_1(int *a,int l,int h)
{
    int pivot=a[h];
    int j=l-1;
    for(int i=l;i<h;i++)
    {
        if(a[i]<pivot)
        {
            j++;
            swap(a[i],a[j]);
        }
    }
    swap(a[j+1],a[h]);
    return j+1;
}
//Method 3........
//Time Complexity is O(n)...
//Auxiliary space is o(1)...........
//Hoore's Partition.......
// We assumed the pivot element is the first-element................

int partition_2(int *a,int l,int h)
{
    int start=l-1;
    int end=h+1;
    int pivot=a[0];
    while(true)
    {
        do
        {
            start++;
        }while(a[start]<pivot);

        do
        {
            end--;
        }while(a[end] > pivot);
        if(start>=end)
            return end;
        swap(a[start],a[end]);
    }
}

int main()
{
    int a[]={5,3,8,4,2,7,1,10};
    partition(a,0,6,6);
    cout<<endl;
    cout << partition_1(a,0,6) << endl;
    cout << partition_2(a,0,6);
}
