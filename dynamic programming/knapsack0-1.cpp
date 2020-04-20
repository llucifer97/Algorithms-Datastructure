/*https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
 * APPROACH1:naive recursive brute force{complexity : time->O(2^n)}
 * APPROACH2:bottom up tabulation {Time Complexity: O(nW) }
 * APPROACH3:top down memoisation
 * APPROACH4: space optimised
 * APPROACH5:meet in the middle(to be implemented) 
 */
 
#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)  
{  
      
// Base Case  
if (n == 0 || W == 0)  
    return 0;  
  
// If weight of the nth item is more  
// than Knapsack capacity W, then  
// this item cannot be included 
// in the optimal solution  
if (wt[n-1] > W)  
    return knapSack(W, wt, val, n-1);  
  
// Return the maximum of two cases:  
// (1) nth item included  
// (2) not included  
else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),  
                    knapSack(W, wt, val, n-1) );  
}  




int knapSack_bu(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
  
   // Build table K[][] in bottom up manner 
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
} 


//top down
/* Returns the value of maximum profit */
int knapSackRec(int W, int wt[], int val[], int i, int** dp) 
{ 
    // base condition 
    if (i < 0) 
        return 0; 
    if (dp[i][W] != -1) 
        return dp[i][W]; 
  
    if (wt[i] > W) { 
  
        // store the value of function call stack in  
        // table before return 
        dp[i][W] = knapSackRec(W, wt, val, i - 1, dp); 
        return dp[i][W]; 
    } 
    else { 
  
        // store value in a table before return 
        dp[i][W] = max(val[i] + knapSackRec(W - wt[i], wt, val, i - 1, dp), 
                       knapSackRec(W, wt, val, i - 1, dp)); 
  
        // return value of table after storing 
        return dp[i][W]; 
    } 
} 
  
int knapSack_td(int W, int wt[], int val[], int n) 
{ 
    int** dp; // double pointer to declare the table dynamically 
    dp = new int*[n]; 
  
    // loop to create the table dynamically 
    for (int i = 0; i < n; i++)  
        dp[i] = new int[W + 1];     
  
    // loop to initially filled the table with -1 
    for (int i = 0; i < n; i++)  
        for (int j = 0; j < W + 1; j++)  
            dp[i][j] = -1; 
    return knapSackRec(W, wt, val, n-1, dp); 
} 


int KnapSack_spaceopt(int val[], int wt[], int n, int W) 
{ 
    // matrix to store final result 
    int mat[2][W+1]; 
    memset(mat, 0, sizeof(mat)); 
  
    // iterate through all items 
    int i = 0; 
    while (i < n) // one by one traverse each element 
    { 
        int j = 0; // traverse all weights j <= W 
  
        // if i is odd that mean till now we have odd 
        // number of elements so we store result in 1th 
        // indexed row 
        if (i%2!=0) 
        { 
            while (++j <= W) // check for each value 
            { 
                if (wt[i] <= j) // include element 
                    mat[1][j] = max(val[i] + mat[0][j-wt[i]], 
                                    mat[0][j] ); 
                else           // exclude element 
                    mat[1][j] = mat[0][j]; 
            } 
  
        } 
  
        // if i is even that mean till now we have even number 
        // of elements so we store result in 0th indexed row 
        else
        { 
            while(++j <= W) 
            { 
                if (wt[i] <= j) 
                    mat[0][j] = max(val[i] + mat[1][j-wt[i]], 
                                     mat[1][j]); 
                else
                    mat[0][j] = mat[1][j]; 
            } 
        } 
        i++; 
    } 
  
    // Return mat[0][W] if n is odd, else mat[1][W] 
    return (n%2 != 0)? mat[0][W] : mat[1][W]; 
} 
  
  //meet in the middle to be also implemented









int main()
{
	int val[] = {60, 100, 120};  
    int wt[] = {10, 20, 30};  
    int W = 50;  
    int n = sizeof(val)/sizeof(val[0]);  
    cout<<knapSack(W, wt, val, n);  
	
  return 0;
}
