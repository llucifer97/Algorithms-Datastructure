//you are given arrival and departure times of the guests, you need to find the time to go to the party so that you can meet maximum people.

#include<bits/stdc++.h>
using namespace std;

int find_time(int a[],int n,int b[],int m)
{
    int i,ma=1,j;
    i=1;
    j=0;
    int count=1;
    while(i < n && j<m)
    {
        if(a[i]<=b[j])
        {
            i++;
            count++;
        }
        else
        {
            j++;
            count--;
        }
        ma=max(count,ma);
    }
    return ma;
}
int main()
{
    int arrival[]={900,600,700};
    int departure[]={1000,800,730};
    sort(arrival,arrival+3);
    sort(departure,departure+3);
    cout << find_time(arrival,3,departure,3);
    return 0;
}
