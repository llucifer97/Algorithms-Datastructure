//Counting sort.........

//Not a Comparison based Algorithm........

//Time Complexity is Theta(n+k)......

//Auxiliary space is Theta(n+k).....

//Stable



#include<bits/stdc++.h>
using namespace std;

//Method 1
//Naive-Implementation.....

//Time Complexity is O(n+k)...................

void count_sort_1(int *a,int n,int k)
{
    int temp[k]={0};
    int index=0;
    for(int i=0;i<n;i++)
    {
        temp[a[i]]++;
    }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<temp[i];j++)
        {
            a[index]=i;
            index++;
        }
    }
    for(int i=0;i<n;i++)
        cout << a[i] <<" ";
}

//Method 2
void counting_sort(int *a,int n,int k)
{
    int count[k];
    for(int i=0;i<k;i++)
    {
        count[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        count[a[i]]++;
    }
    for(int i=1;i<k;i++)
    {
        count[i]=count[i-1]+count[i];
    }
    int output[n];
    for(int i=n-1;i>=0;i--)
    {
        output[count[a[i]-1]]=a[i];
        count[a[i]]--;
    }
    for(int i=0;i<n;i++)
    {
        a[i]=output[i];
    }
    for(int i=0;i<n;i++)
        cout << output[i] <<" ";
}

int main()
{
    int a[]={1,4,4,1,0,1};
    //count_sort_1(a,6,5);
    //cout<<endl;
    counting_sort(a,6,5);
    return 0;
}
