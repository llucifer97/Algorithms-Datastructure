//Quick sort
//Divide and Conquer
//Key part is Partitioning (Hoore,Lomoto,Naive)
//Worst Time Complexity is O(n**2).....//we can avoid this by using random partitioning.........
//Despite having higher worst case time,it is preferred over other algorithm many times due to following reasons..........
// 1.Tail Recursive
// 2.In-place
// 3.Cache-friendly.....
// 4.Best and Average Case :Theta(n*log(n))............


//Auxiliary space :
//Best case and Average Case:O(log(n)).........
//Worst case is O(n).............
#include<bits/stdc++.h>
using namespace std;
//Using Lomuto-Partitioning

int lomuto_parition(int *a,int l,int h)
{
    int k=l-1;
    int pivot=a[h];
    for(int i=l;i<h;i++)
    {
        if(a[i] < pivot)
        {
            k++;
            swap(a[i],a[k]);
        }
    }
    swap(a[k+1],a[h]);
    return (k+1);
}
void quick_sort(int *a,int l,int h)
{
    if(h > l)
    {
        int p=lomuto_parition(a,l,h);
        quick_sort(a,l,p-1);
        quick_sort(a,p+1,h);
    }
}
//Using Hoore's-Partitioning
int Hoore_parition(int *a,int l,int h)
{
    int low=l-1;
    int high=h+1;
    int pivot=a[h];
    while(true)
    {
        do
        {
           low++;
        }while(a[low] < pivot);
        do
        {
            high--;
        }while(a[high]>pivot);
        if(low>=high)
            return high;
        swap(a[low],a[high]);
    }
}
void quick_sort_Hoore(int *a,int l,int h)
{
    if(h > l)
    {
        int p=Hoore_parition(a,l,h);
        quick_sort_Hoore(a,l,p);
        quick_sort_Hoore(a,p+1,h);
    }
}

void display(int *a,int n)
{
        for(int i=0;i<n;i++)
        cout<< a[i] <<" ";
}
int main()
{
    int a[]={8,4,7,9,3,10,5};
    quick_sort(a,0,6);
    display(a,7);
    cout<<endl;
    quick_sort(a,0,6);
    display(a,7);
    return 0;
}
