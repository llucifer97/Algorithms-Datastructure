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
