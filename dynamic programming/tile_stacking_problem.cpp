// C++ program to solvse the Tile Stacking problem by DP
#include <iostream>
#include<cstring>

using namespace std;

long int tileStackingProblem(int n, int m, int k){
   // in case of larger input data, declare the following arrays globaly.
   // as global variables are declared in heap so it will get rid of memory overflow problem.
   long int dp[n+1][m+1];
   long int prefixsum[n+1][m+1];
   
    memset(dp, 0, sizeof(dp));
    memset(prefixsum, 0, sizeof(prefixsum));

    // Initialing 0th column of dp to 0. i.e.
    //If we have n left but m is 0, this means it is not possible to stack any more tile,
    //thus setting it to 0
    for(int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
        prefixsum[i][0] = 1;
    }

    // Initialing 0th Row to 1. i.e.
    //If we have n=0 left and m tiles remains, this means we successfully built a stable stack,
    //thus setting it to 1
    for(int i = 0; i < m + 1; ++i)
    {
        dp[0][i] = 1;
        prefixsum[0][i] = 1;
    }

    // For each column from 1 to m
    for (int j = 1; j < m + 1; j++)//j represents size of stack
    {
        // For each row from 1 to n.
        for (int i = 1; i < n + 1; i++)//i represents no. of tiles in a stck
        {
            // Initialing dp[i][j] to presum of (i, j - 1).
            dp[i][j] = prefixsum[i][j - 1];

            if (i > k)
            {
                dp[i][j] = dp[i][j] - prefixsum[i - k - 1][j - 1];
            }
        }

        // Calculating prefixsum for each i, 1 <= i <= n.
        for (int i = 1; i < n + 1; i++)
            prefixsum[i][j] = dp[i][j] + prefixsum[i - 1][j];
    }
    
    
for(int i =0;i<=n;i++){
	for(int j =0;j<=m;j++){
		cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	
	cout << "\n";
	cout << "\n";
	
	   
for(int i =0;i<=n;i++){
	for(int j =0;j<=m;j++){
		cout << prefixsum[i][j] << " ";
		}
		cout << "\n";
	}

    return dp[n][m];
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    cout<<"Tatal possible stable stacks = "<<tileStackingProblem(n ,m ,k)<<'\n';

    return 0;
}



/*
 *3 3 2
1 1 1 1 
0 1 2 3 
0 1 3 6 
0 0 2 7 


1 1 1 1 
1 2 3 4 
1 3 6 10 
1 3 8 17 
Tatal possible stable stacks = 7

*/
