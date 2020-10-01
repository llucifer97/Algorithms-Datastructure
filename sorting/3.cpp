//Intersection of two sorted arrays..

#include<bits/stdc++.h>
using namespace std;

//Method-1
//Naive-solution.....
//Time complexity is O(n1*n2)............
void find_intersect(int *a,int *b,int n1,int n2)
{
    for(int i=0;i<n1;i++)
    {
        if(i>0 && a[i]==a[i-1])
            continue;
        for(int j=0;j<n2;j++)
        {
            if(a[i]==b[j])
            {
                cout << a[i]<<" ";
            }
        }
    }
}

//Method2---------
//Time Complexity is O(n1+n2)...........

void find_intersect_1(int *a,int *b,int n1,int n2)
{
    int i=0,j=0;
    while(i < n1 && j<n2)
    {
        if(a[i]==a[i-1] && i>0){
                i++;
            continue;
        }
        if(b[j] > a[i])
        {
            i++;
        }
        else if(a[i]>b[j])
            j++;
        else
        {
            cout << a[i] <<" ";
            i++;j++;
        }
    }
}
int main()
{
    int a[]={3,5,10,10,10,15,15,20};
    int b[]={5,10,10,15,30};
    find_intersect(a,b,8,5);
    cout<<endl;
    find_intersect_1(a,b,8,5);
}
