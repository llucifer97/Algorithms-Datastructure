///Cycle-sort
//This algorithm is used when the memory cost is expensive
//In this algorithm ,we find how many elements are smaller than current element then we will place the current element at correct position..
//We maintain a cycle between the elements.
//Find the minimum swaps required to sort the array.............
//Time complexity is :
//Worst case : O(n**2)..........
//In-place and not stable........

#include<bits/stdc++.h>
using namespace std;



void cycle_sort(int *a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int item=a[i];
        int pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(item > a[j])
            {
                pos++;
            }
        }
        swap(item,a[pos]);
        while(pos!=i)
        {
            pos=i;
            for(int j=i+1;j<n;j++)
            {
                if(item > a[j])
                {
                    pos++;
                }
            }
            swap(a[pos],item);
        }
    }
}
void display(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        cout << a[i] <<" ";
    }
}
int main()
{
    int a[]={5,4,3,2,1};
    cycle_sort(a,5);
    display(a,5);
    return 0;
}


