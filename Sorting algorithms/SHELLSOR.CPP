#include<IOSTREAM.H>
#include<conio.h>
class shellsort
{
 private:
 int a[20],n,i,j,gap,temp;
 public:
 void getdata()
 {
 cout<<"enter number of elemnts:\n";
 cin>>n;
 cout<<"enter the elements:\n";
  for(i=0;i<n;i++)
  {
   cin>>a[i];
  }
 }
 void shellsorting()
 {

 for(gap=n/2;gap>0;gap=gap/2)
 {
  for(j=gap;j<n;j++)
  {
   for(i=j-gap;i>=0;i-=gap)
   {
    if(a[i+gap]>a[i])
    {
    break;
    }
    else
    {
     swap();
    }
   }
  }
 }
}
 void swap()
 {
   temp=a[i+gap];
   a[i+gap]=a[i];
   a[i]=temp;

 }
void display()
{
 for(i=0;i<n;i++)
 {
  cout<<a[i]<<"\t";
 }
}
};
void main()
{
 clrscr();
 shellsort obj;
 obj.getdata();
 cout<<"before sorting:";
 obj.display();
 obj.shellsorting();
 cout<<endl<<"after sorting:";
 obj.display();
 getch();
}
