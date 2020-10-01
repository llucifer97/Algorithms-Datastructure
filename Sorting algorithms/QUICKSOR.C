#include<stdio.h>
#include<conio.h>
void quicksort(int[],int,int);
void main()
{
int a[50],n,i;
clrscr();
printf("enter number of elemnts that u want to store:\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
quicksort(a,0,n-1);
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
getch();
}
void quicksort(int a[],int low,int high)
 {
   int pivot,i,j,temp;
   if(low<high)
   {
   pivot=low;
   i=low;
   j=high;
   while(i<j)
    {
      while(a[i]<=a[pivot] && i<=high)
      {
      i++;
      }
      while(a[j]>a[pivot] && j>=low)
      {
      j--;
      }
      if(i<j)
      {
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
      }
    }
    temp=a[j];
    a[j]=a[pivot];
    a[pivot]=temp;
    quicksort(a,low,j-1);
    quicksort(a,j+1,high);
    }
 }

