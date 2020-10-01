#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int n,a[50],i,j,temp;
printf("enter number of elements that you want to store:\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]>a[j]) //if you change the relational operator u will get desceding order
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("acending order of the elements is:");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
getch();
}