//Count Inversions in Array...............
//two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

//Method 1
//Naive Solution...

#include<bits/stdc++.h>
using namespace std;

int count_inversion(int *a,int n)
{
    int count=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i] > a[j])
                count++;
        }
    }
    return count;
}
//Method2......
//Time Complexity is O(n*log n)................
//Aux space is O(n)...........
int merge(int *a,int l,int m,int h)
{
    int n1=m-l+1;
    int n2=h-m;
    int left[n1];
    int right[n2];
    for(int i=0;i<n1;i++)
    {
        left[i]=a[i+l];
    }
    for(int i=0;i<n2;i++)
    {
        right[i]=a[m+i+1];
    }
    int i,j,k;
    i=j=0;
    k=l;
    int c=0;
    while(i < n1 && j < n2)
    {
        if(left[i]<=right[j])
        {
            a[k]=left[i];
            i++;
        }
        else{
            a[k]=right[j];
            j++;
            c=c+(n1-i);
        }
        k++;
    }
    while(i < n1)
    {
        a[k]=left[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        a[k]=right[j];
        j++;
        k++;
    }
    return c;

}
int count_inversion_eff(int *a,int l,int h)
{
    int res=0;
    if(l < h)
    {
        int m=l+(h-l)/2;
        res+=count_inversion_eff(a,l,m);
        res+=count_inversion_eff(a,m+1,h);
        res+=merge(a,l,m,h);
    }
    return res;

}



int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1};
    cout << count_inversion(a,10) << endl;
    cout << count_inversion_eff(a,0,9);
    return 0;
}
