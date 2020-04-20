/*https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10
 *https://www.geeksforgeeks.org/knapsack-with-large-weights/?ref=rp : Knapsack with large Weights
 *https://www.geeksforgeeks.org/double-knapsack-dynamic-programming/?ref=rp  : double knapsack
 *https://www.geeksforgeeks.org/0-1-knapsack-using-branch-and-bound/?ref=rp  :branch and bound
 * APPROACH1:naive recursive brute force{complexity : time->O(2^n)}
 * APPROACH2:bottom up tabulation {Time Complexity: O(nW) }
 * APPROACH3:top down memoisation
 * APPROACH4: space optimised in 2d array
 * APPROACH5: space optimised in 1d array
 * APPROACH6:meet in the middle(to be implemented) 
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
   
   
    // stores the result of Knapsack 
    int res = K[n][W];     
    printf("%d\n", res); 
      
    w = W; 
    for (i = n; i > 0 && res > 0; i--) { 
          
        // either the result comes from the top 
        // (K[i-1][w]) or from (val[i-1] + K[i-1] 
        // [w-wt[i-1]]) as in Knapsack table. If 
        // it comes from the latter one/ it means  
        // the item is included. 
        if (res == K[i - 1][w])  
            continue;         
        else { 
  
            // This item is included. 
            printf("%d ", wt[i - 1]); 
              
            // Since this weight is included its  
            // value is deducted 
            res = res - val[i - 1]; 
            w = w - wt[i - 1]; 
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


//more space optimes 1d array
int KnapSack_1d(int val[], int wt[], int n, int W) 
{ 
    // array to store final result 
    //dp[i] stores the profit with KnapSack capacity "i" 
    int dp[W+1]; 
      
    //initially profit with 0 to W KnapSack capacity is 0 
    memset(dp, 0, sizeof(dp)); 
  
    // iterate through all items 
    for(int i=0; i < n; i++)  
        //traverse dp array from right to left 
        for(int j=W; j>=wt[i]; j--) 
            dp[j] = max(dp[j] , val[i] + dp[j-wt[i]]); 
    /*above line finds out maximum of  dp[j](excluding ith element value) 
      and val[i] + dp[j-wt[i]] (including ith element value and the 
      profit with "KnapSack capacity - ith element weight") */    
    return dp[W]; 
} 
  
  //meet in the middle to be also implemented









int main()
{
	int val[] = {60, 100, 120};  
    int wt[] = {10, 20, 30};  
    int W = 50;  
    int n = sizeof(val)/sizeof(val[0]);  
    cout<<knapSack_bu(W, wt, val, n);  
	
  return 0;
}
