#include<bits/stdc++.h>
using namespace std;
int arr[1000][1000]={0};
static int tile_no=0;
void assign_value(int x_start, int y_start )
{
	    tile_no+=1;
		arr[x_start][y_start]=tile_no;
		arr[x_start+1][y_start]=tile_no;
		arr[x_start][y_start+1]=tile_no;
		arr[x_start+1][y_start+1]=tile_no;
}
void place_tiles(int x_start,int y_start,int len,int x,int y)
{	
	int p = arr[x][y];
	if(len==2)
	{
		assign_value(x_start,y_start);
		arr[x][y]=p;
		return;
	}
	    int x_mid=x_start-1+(len/2);
	    int y_mid=y_start-1+(len/2);
		assign_value(x_mid,y_mid);

		if(x<=x_mid && y<=y_mid)
		{
			arr[x_mid][y_mid]=0;
			arr[x][y]=p;

		place_tiles(x_start,y_start,len/2,x,y);
		place_tiles(x_start,y_mid+1,len/2,x_mid,y_mid+1);
		place_tiles(x_mid+1,y_start,len/2,x_mid+1,y_mid);
		place_tiles(x_mid+1,y_mid+1,len/2,x_mid+1,y_mid+1);

		}
		else if(x>x_mid && y<=y_mid)
		{
			arr[x_mid+1][y_mid]=0;
			arr[x][y]=p;

		place_tiles(x_start,y_start,len/2,x_mid,y_mid);
		place_tiles(x_start,y_mid+1,len/2,x_mid,y_mid+1);
		place_tiles(x_mid+1,y_start,len/2,x,y);
		place_tiles(x_mid+1,y_mid+1,len/2,x_mid+1,y_mid+1);
		}
		else if(x<=x_mid && y>y_mid)
		{
			arr[x_mid][y_mid+1]=0;
			arr[x][y]=p;

		place_tiles(x_start,y_start,len/2,x_mid,y_mid);
		place_tiles(x_start,y_mid+1,len/2,x,y);
		place_tiles(x_mid+1,y_start,len/2,x_mid+1,y_mid);
		place_tiles(x_mid+1,y_mid+1,len/2,x_mid+1,y_mid+1);

		}
		else
		{
			arr[x_mid+1][y_mid+1]=0;
			arr[x][y]=p;
		place_tiles(x_start,y_start,len/2,x_mid,y_mid);
		place_tiles(x_start,y_mid+1,len/2,x_mid,y_mid+1);
		place_tiles(x_mid+1,y_start,len/2,x_mid+1,y_mid);
		place_tiles(x_mid+1,y_mid+1,len/2,x,y);
		}


}
int main()
{
	int n,x,y;
	cout<<"Enter n (max 999) :";
	cin>>n;
	cout<<endl<<"Enter x of missing tile(0-indexing)";
	cin>>x;

	cout<<endl<<"Enter y of missing tile(0-indexing)";
	cin>>y;
	arr[x][y]=-1;
	place_tiles(0,0,n,x,y);
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"-1 represents missing tile";
}
