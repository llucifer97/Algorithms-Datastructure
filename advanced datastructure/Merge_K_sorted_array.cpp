    #include<bits/stdc++.h>
    using namespace std;
     
    #define N 4
     
    struct node
    {
    	int val;
    	int a;
    	int b;
    };
     
    class comp
    {
    	public :
    	bool operator () (node a,node b)
    	{
    		if(a.val>b.val) return true;
    		return false;
    	}
    };
     
    void sorted_print(int a[][N])
    {
    	priority_queue <node,vector<node>,comp> pq;
    	node ptr,pp;
    	int idx,idy;
    	for(int i=0;i<N;i++)
    	{
    		ptr.val = a[i][0];
    		ptr.a = i;
    		ptr.b = 0;
     
    		pq.push(ptr);
    	}
     
    	while(!pq.empty())
    	{
    		ptr = pq.top();
    		pq.pop();
     
    		cout<<ptr.val<<" ";
    		idx = ptr.a;
    		idy=ptr.b;
     
    		if(idx<N && (idy+1)<N)
    		{
    			pp.val = a[idx][idy+1];
    			pp.a = idx;
    			pp.b = idy+1;
    			pq.push(pp);
    		}
    	}
    	return ;
    }
     
    int main()
    {
    	int a[N][N] = {{2, 6, 12, 34},
                         {1, 9, 20, 1000},
                         {23, 34, 90, 2000},
                         {100,157,169,3000}
                      };
     
        sorted_print(a);
    return 0;
    }
