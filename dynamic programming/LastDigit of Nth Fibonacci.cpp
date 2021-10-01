
/*  Program to print last digit of nth fibonacci
Input:
N = 14
Output:
7
Explanation:
14th Fibonacci number is 377
It's last digit is 7

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int fib(int n){
        if(n==0)
        return 0;
        else if(n==1 || n==2)
        return 1;
        else
        {
            int a[n];
            a[0]=1;
            a[1]=1;
            for(int i=2;i<n;i++)
            a[i]=(a[i-1]+a[i-2])%10;
            return a[n-1];
        }
        
    }
};


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.fib(N) << endl;
    }
    return 0; 
} 
