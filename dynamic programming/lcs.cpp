/*https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
 * 
 *approach1: naive recursive implementation(space:O(m + n)
 * approach2 :top down memoization applied in recursive solution|| Time Complexity: O(N * M),Auxiliary Space: (N * M)
 * approach3: bottom up
 * ap[roach4:space optimised bottom up(O(n))
 * more info:https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
 * https://www.ics.uci.edu/~eppstein/161/960229.html
 * 
 * 
 * 
 * 
 * /
 */
#include <bits/stdc++.h>
using namespace std;




int lcs_recursive( string X, string Y, int m, int n )  
{  
    if (m == 0 || n == 0)  
        return 0;  
    if (X[m-1] == Y[n-1])  
        return 1 + lcs_recursive(X, Y, m-1, n-1);  
    else
        return max(lcs_recursive(X, Y, m, n-1), lcs_recursive(X, Y, m-1, n));  
}  


  
const int maximum = 1000; 
  
// Returns length of LCS for X[0..m-1], Y[0..n-1] */ 
// memoization applied in recursive solution 
int lcs_memoization(string X, string Y, int m, int n, int dp[][maximum]) 
{ 
    // base case 
    if (m == 0 || n == 0) 
        return 0; 
  
    // if the same state has already been 
    // computed 
    if (dp[m - 1][n - 1] != -1) 
        return dp[m - 1][n - 1]; 
  
    // if equal, then we store the value of the 
    // function call 
    if (X[m - 1] == Y[n - 1]) { 
  
        // store it in arr to avoid further repetitive 
        // work in future function calls 
        dp[m - 1][n - 1] = 1 + lcs_memoization(X, Y, m - 1, n - 1, dp); 
  
        return dp[m - 1][n - 1]; 
    } 
    else { 
  
        // store it in arr to avoid further repetitive 
        // work in future function calls 
        dp[m - 1][n - 1] = max(lcs_memoization(X, Y, m, n - 1, dp), 
                               lcs_memoization(X, Y, m - 1, n, dp)); 
  
        return dp[m - 1][n - 1]; 
    } 
} 

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs_bu( string X, string Y, int m, int n )  
{  
    int L[m + 1][n + 1];  
   // int i, j;  
      
    /* Following steps build L[m+1][n+1] in  
       bottom up fashion. Note that L[i][j]  
       contains length of LCS of X[0..i-1] 
       and Y[0..j-1] */
    for (int i = 0; i <= m; i++)  
    {  
        for (int j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            L[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            L[i][j] = L[i - 1][j - 1] + 1;  
      
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  
          
    /* L[m][n] contains length of LCS  
    for X[0..n-1] and Y[0..m-1] */
  ///////////////////////////////////////////////////////////////////  
     // Following code is used to print LCS 
   int index = L[m][n]; 
  
   // Create a character array to store the lcs string 
   char lcs[index+1]; 
   lcs[index] = '\0'; // Set the terminating character 
  
   // Start from the right-most-bottom-most corner and 
   // one by one store characters in lcs[] 
   int i = m, j = n; 
   while (i > 0 && j > 0) 
   { 
      // If current character in X[] and Y are same, then 
      // current character is part of LCS 
      if (X[i-1] == Y[j-1]) 
      { 
          lcs[index-1] = X[i-1]; // Put current character in result 
          i--; j--; index--;     // reduce values of i, j and index 
      } 
  
      // If not same, then find the larger of two and 
      // go in the direction of larger value 
      else if (L[i-1][j] > L[i][j-1]) 
         i--; 
      else
         j--; 
   } 
  
   // Print the lcs 
   cout << "LCS of " << X << " and " << Y << " is " << lcs; 
    return L[m][n];  
}  


int lcs_space_optimised(string &X, string &Y) 
{ 
      
    // Find lengths of two strings 
    int m = X.length(), n = Y.length(); 
  
    int L[2][n + 1]; 
  
    // Binary index, used to 
    // index current row and 
    // previous row. 
    bool bi; 
  
    for (int i = 0; i <= m; i++) 
    { 
          
        // Compute current  
        // binary index 
        bi = i & 1; 
  
        for (int j = 0; j <= n; j++) 
        { 
            if (i == 0 || j == 0) 
                L[bi][j] = 0; 
  
            else if (X[i-1] == Y[j-1]) 
                 L[bi][j] = L[1 - bi][j - 1] + 1; 
  
            else
                L[bi][j] = max(L[1 - bi][j],  
                               L[bi][j - 1]); 
        } 
    } 
  
    // Last filled entry contains 
    // length of LCS 
    // for X[0..n-1] and Y[0..m-1]  
    return L[bi][n]; 
} 



int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	int m = s1.size();
	int n = s2.size();

	 int dp[m][maximum]; 
  
    // assign -1 to all positions 
    memset(dp, -1, sizeof(dp)); 
    
  // cout << lcs_recursive(s1,s2,m,n);
   cout << lcs_bu(s1,s2,m,n);
 // cout <<  lcs_space_optimised(s1,s2);
    
   //cout<< lcs_memoization(s1,s2,m,n,dp);
  return 0;
}
