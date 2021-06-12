//Sort an array of three types of elements.........

#include<bits/stdc++.h>
using namespace std;

//Naive Method.........
void sort_3(int *a,int n)
{
    int temp[n];
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            temp[index]=a[i];
            index++;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            temp[index]=a[i];
            index++;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(a[i]==2)
        {
            temp[index]=a[i];
            index++;
        }
    }
    for(int i=0;i<n;i++)
    {
        a[i]=temp[i];
    }
}
//Efficient Solution......

void sort_effiecient(int *a,int n)
{
    int l,h,m;
    l=0;
    m=0;
    h=n-1;

    while (m<=h)
    {
        switch(a[m])
        {
        case 0:
            swap(a[l],a[m]);
            l++;
            m++;
            break;
        case 1:
            m++;
            break;
        case 2:
            swap(a[m],a[h]);
            h--;
            break;
        }
    }
}
int main()
{
    int a[]={0,1,1,2,0,1,1,2,2};
    //sort_3(a,8);
    sort_effiecient(a,9);
    for(int i=0;i<8;i++)
        cout <<a[i]<<" ";
    return 0;
}


