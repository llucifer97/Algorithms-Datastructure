//InPlace-Algorithm.......



//Bubble Sort
//Stable

#include<bits/stdc++.h>
using namespace std;

//Time Complexity is O(n**2)........

void bubble_sort(int *a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int temp=true;
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                temp=false;
            }
        }
        if(temp)
            break;
    }

}
//Selection sort
//Unstable
//Time Complexity is O(n**2)...........

void selection_sort(int *a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[min_index]>a[j])
                min_index=j;
        }
        swap(a[i],a[min_index]);
    }
}
//Insertion sort
//stable........

//Time Complexity is O(n**2)......
void insertion_sort(int *a,int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=a[i],j;
        for(j=i-1;j>=0 && a[j]>temp;j--)
            a[j+1]=a[j];
        a[j+1]=temp;
    }
}
int main()
{
    int a[]={5,4,3,2,1};
    bubble_sort(a,5);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    selection_sort(a,5);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    insertion_sort(a,5);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
        return 0;
}
