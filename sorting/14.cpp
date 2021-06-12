//Chocolate Distribution Problem......

#include<bits/stdc++.h>
using namespace std;

//Time complexity is O(n*log(n))......

int difference_chocolate(int *a,int n,int m)
{
    int ans=INT_MAX;
    for(int i=0;i<=n-m;i++)
    {
        ans=min(ans,a[m+i-1]-a[i]);
    }
    return ans;
}
int main()
{
    int a[]={3,4,1,9,56,7,9,12};
    sort(a,a+8);
    cout << difference_chocolate(a,8,5);
    return 0;
}
