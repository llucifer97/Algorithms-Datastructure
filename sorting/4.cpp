//Union of two sorted array...

//Method 1
//Time complexity is O(m+n*log(m+n))......
//Auxiliary space is O(m+n).......

#include<bits/stdc++.h>
using namespace std;

//Method 1
//Time complexity is O(m+n)......
//Auxiliary space is O(m+n).........
void find_union(int *a,int *b,int m,int n)
{
    int temp[m+n];
    int p=m+n;
    for(int i=0;i<m;i++)
    {
        temp[i]=a[i];
    }
    for(int i=0;i<n;i++)
    {
        temp[i+m]=b[i];
    }
    sort(temp,temp+p);
    for(int i=0;i<p;i++)
    {
        if(i==0 || temp[i]!=temp[i-1])
            cout << temp[i]<<" ";
    }

}

//Method 2
//Time complexity is O(m+n)......
//Auxiliary space is O(1)....................



void find_union_1(int *a,int *b,int m,int n)
{
    int i=0;
    int j=0;
    while(i < n && j<m)
    {
        if(a[j]==a[j-1] && j>0)
        {
            j++;
            continue;
        }
        if(b[i]==b[i-1] && i>0)
        {
            i++;
            continue;
        }
        if(a[j] > b[i])
        {
            cout << b[i]<<" ";
            i++;
        }
        else if(b[i] > a[j])
        {
            cout << a[j]<<" ";
            j++;
        }
        else
        {
            cout << a[j] <<" ";
            i++;
            j++;
        }

    }
    while(i < n)
    {
        if(b[i]!=b[i-1] || i==0)
        {
            cout << b[i] <<" ";
            i++;

        }
    }
    while( j < m)
    {
        if(a[j]!=a[j-1] || j==0)
        {
            cout << a[j] <<" ";
            j++;

        }

    }
}


int main()
{
    int a[]={3,8,10};
    int b[]={2,8,9,10,15};
    find_union(a,b,3,5);
    cout << endl;
    find_union_1(a,b,3,5);
}
