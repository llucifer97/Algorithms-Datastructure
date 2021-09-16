// https://a.hirepro.in/dF7LDQ0O
// User Name: Qualcomm241743760563
// Password: 9BtrYQqu


#include<bits/stdc++.h>
using namespace std;


long CalculateCoeff(int n,int k) 
    {
        long res=1;
        if(k>n-k)
            k=n-k;                    
        for(int i=0;i<k;i++)
        {
            res*=(n-i);
            res/=(i+1);
        }
        return res;
    }



    int numTrees(int n) 
    {
        return CalculateCoeff(2*n,n)/(n+1)%100000007;
    }

    vector<int> numBST(vector<int> nodeValues) 
    {
        int n = nodeValues.size();
        vector<int> result;
        for(int i : nodeValues)
        {
           int ans =  numTrees(i);
           result.push_back(ans);
        }

        return result;
    }



    int main()
    {

        
        int n;
        cin >> n;
         vector<int> temp(n);

        for(int i =0;i<n;i++) 
        {
            int x;
            cin >> x;
            temp[i] = x;
           
        }
        
       


        vector<int> a = numBST(temp);


        for(auto i : a)
        {
            cout << i << "\n";
        }
       
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


vector<int> adj[100005];

int visited[100005] = {0};




void dfs(int node , priority_queue<int> q)
{
    if(visited[node] == 1)return;
    visited[node] = 1;
    q.push(node);
    for(auto i : adj[node])
    {
        if(!visited[i])
        {
            dfs(i,q);
        }
    }

}





int countCompanies(int friend_nodes , vector<int> friend_from , vector<int> friend_to , vector<int> friends_weight )
{
    for(int i =0;i<friend_nodes;i++)
    {
        adj[friend_from[i]].push_back(friends_weight[i]);
        adj[friend_to[i]].push_back(friend_from[i]);
    }

    int ans = INT_MIN;

    for(int i =1;i<=friend_nodes;i++)
    {
        int temp = INT_MIN;
         priority_queue<int> q;
         

        if(!visited[i])
        {
            dfs(i,q);
            int m1 = q.top();
            q.pop();
            int m2 = q.top();
            q.pop();
            temp = max(temp,m1*m2);
        }
        ans = max(ans,temp);
    }
    return ans;
}
