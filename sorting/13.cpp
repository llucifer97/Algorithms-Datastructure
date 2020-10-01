//Find the Kth smallest Element.....

#include<bits/stdc++.h>
using namespace std;

//Method1...........
//Time Complexity is O(n*log(n)).........

int find_k_element(int *a,int n,int k)
{
    return a[k-1];
}

//Method2............
int find_pivot(int *a,int l,int h)
{
    int k=l-1;
    int pivot=a[h];
    for(int i=l;i<h;i++)
    {
        if(a[i] <  pivot)
        {
            k++;
            swap(a[k],a[i]);
        }
    }
    swap(a[k+1],a[h]);
    return k+1;
}
int find_pos_k(int *a,int n,int k)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {

        int p=find_pivot(a,low,high);
        if(p==k-1)
            return p;
        if(k-1 > p)
        {
            low=p+1;
        }
        else if(k-1 < p)
        {
            high=p-1;
        }
    }
    return -1;
}

int main()
{
    int a[] = { 51, 86, 34, 79, 92, 68, 14, 47, 22, 6};
    sort(a,a+10);
    cout << find_k_element(a,5,2) << endl;
        for(int i=0;i<10;i++)
        {
            cout << a[find_pos_k(a,10,i+1)]<<" ";
        }
    return 0;
}
