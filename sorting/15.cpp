//Sort an array with two elements.......
//Segregate negative or positive elements........

#include<bits/stdc++.h>
using namespace std;

//Naive Method........

void sort_two(int *a,int n)
{
    int temp[n],index=0;

    for(int i=0;i<n;i++)
    {
      if(a[i] < 0)
      {
          temp[index]=a[i];
          index++;
      }
    }

    for(int i=0;i<n;i++)
    {
      if(a[i] >=0)
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
//efficient method.....
void sort_2(int *a,int n)
{
    int i=-1;
    int j=n;
    while(true)
    {
        do{i++;}while(a[i]<0);

        do{j--;}while(a[j]>=0);
        if(i>=j)
            return;
        swap(a[i],a[j]);
    }
}
int main()
{
    int a[]={15,-3,-2,16,-3,-2,15,16};
    //sort_two(a,8);
    sort_2(a,8);
    for(int i=0;i<8;i++)
    {
        cout << a[i] <<" ";
    }
    return 0;
}
