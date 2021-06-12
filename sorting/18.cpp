//Merge Overlapping intervals....
#include<bits/stdc++.h>
using namespace std;
struct interval
{
    int start,end;
};

void merge_interval(struct interval arr[],int n)
{
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(arr[res].end>=arr[i].start)
        {
            arr[res].start=min(arr[res].start,arr[i].start);
            arr[res].end=max(arr[res].end,arr[i].end);
        }
        else{
            res++;
            arr[res]=arr[i];
        }
    }
    for(int i=0;i<=res;i++)
        cout << arr[i].start <<" " << arr[i].end <<endl;
}
bool compare(interval a,interval b)
{
    return a.start < b.end;
}
int main()
{
    interval arr[]={ {5,10}, {3,15}, {18,30}, {2,7} };
    sort(arr,arr+4,compare);
    merge_interval(arr,4);
    return 0;
}
