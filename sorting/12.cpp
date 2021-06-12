#include<bits/stdc++.h>
using namespace std;
//Radix sort
//This algorthim is the extended version of counting sort because the data may be is  in the range of 1 to k**2,that's why we use this algorithm insteed of using Counting sort.
//In this algorithm we will sort the array acc.to digits.
//We will first sort it acc to least significant digit ,then sort it acc to middle digit and finally sort it acc to  most significant digit.
//The whole logic is similar to counting sort......

//Time Complexity is Theta(d*(n+b))........
//b is the base
//here b=10;
//Auxiliary space is Theta(n+b)..........

//counting-sort
void counting_sort(int *a,int n,int exp)
{
    int count[10]={0};
    for(int i=0;i<n;i++)
    {
        count[(a[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--)
    {
        output[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++)
    {
        a[i]=output[i];
    }
}
void radix_sort(int *a,int n)
{
    int m=a[0];
    for(int i=1;i<n;i++)
        m=max(m,a[i]);

    //Run loop through  number of digits in a maximum number .......

    for(int exp=1;m/exp>0;exp=exp*10)
    {
        counting_sort(a,n,exp);
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int a[]={319,212,6,8,100,50};
    radix_sort(a,6);
    return 0;
}
