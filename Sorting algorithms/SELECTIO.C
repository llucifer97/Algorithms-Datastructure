#include<stdio.h>
#include<conio.h>
void main()
{
int a[50],n,i,j,min,temp;
printf("enter number of elements that u want to store:\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<n-1;i++)
{
min=i;
for(j=i+1;j<n;j++)
{
if(a[min]>a[j])
{
min=j;
}
}
if(min!=i)
{
temp=a[i];
a[i]=a[min];
a[min]=temp;
}
}
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
getch();
}