//Optimized Quick sort for worst case..........

///When does the worst case of Quicksort occur?
/*
) Array is already sorted in same order.
2) Array is already sorted in reverse order.
3) All elements are same (special case of case 1 and 2)
*/




#include<bits/stdc++.h>
using namespace std;


//Lomuto-partition............

int lomuto_parition(int *a,int l,int h)
{
    int k=l-1;
    int pivot=a[h];
    for(int i=l;i<h;i++)
    {
        if(a[i] < pivot)
        {
            k++;
            swap(a[i],a[k]);
        }
    }
    swap(a[k+1],a[h]);
    return (k+1);
}

int random_partion_Lomuto(int *a,int l,int h)
{
    int ra=l + rand()%(h-l);
    swap(a[h],a[ra]);
    return lomuto_parition(a,l,h);
}

void Randomized_Quick_sort_lomuto(int *a,int l,int h)
{
    if(l < h)
    {
        int p=random_partion_Lomuto(a,l,h);
        Randomized_Quick_sort_lomuto(a,l,p-1);
        Randomized_Quick_sort_lomuto(a,p+1,h);
    }
}

//Hoore's Partition//

int Hoore_parition(int *a,int l,int h)
{
    int beg=l-1;
    int end=h+1;
    int pivot=a[l];
    while(7)
    {
        do
        {
            beg++;
        }while(a[beg] < pivot);

        do
        {
            end--;
        }while(a[end] > pivot);

        if(beg>=end)
            return end;
        swap(a[beg],a[end]);

    }
}

int random_partion_Hoore(int *a,int l,int h)
{
    int ra=l + rand()%(h-l);
    swap(a[l],a[ra]);
    return Hoore_parition(a,l,h);
}
void Randomized_Quick_sort_Hoore(int *a,int l,int h)
{
    if(h > l)
    {
        int p=random_partion_Hoore(a,l,h);
        Randomized_Quick_sort_Hoore(a,l,p);
        Randomized_Quick_sort_Hoore(a,p+1,h);
    }
}
void display(int *a,int n)
{
    for(int i=0;i<n;i++)
            cout << a[i] <<" ";
}
int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1};
    Randomized_Quick_sort_Hoore(a,0,9);
   Randomized_Quick_sort_lomuto(a,0,9);
    display(a,10);
}




