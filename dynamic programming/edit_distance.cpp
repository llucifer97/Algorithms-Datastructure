/*https://www.geeksforgeeks.org/edit-distance-dp-5/
 * APPROACH1:recursion
 * approach2: bottom up  Time Complexity: O(m x n)  Auxiliary Space: O(m x n)
 * approach3: space optimised Time Complexity: O(m x n) Auxiliary Space: O( m )
 * approach4:top down memoisation  Time Complexity: O(M * N) Auxiliary Space: O(M * N)
 */
 
 
 
#include <bits/stdc++.h> 
using namespace std; 
const int maximum = 1000; 
// Utility function to find minimum of three numbers 
int min(int x, int y, int z) 
{ 
	return min(min(x, y), z); 
} 

int editDist(string str1, string str2, int m, int n) 
{ 
	// If first string is empty, the only option is to 
	// insert all characters of second string into first 
	if (m == 0) 
		return n; 

	// If second string is empty, the only option is to 
	// remove all characters of first string 
	if (n == 0) 
		return m; 

	// If last characters of two strings are same, nothing 
	// much to do. Ignore last characters and get count for 
	// remaining strings. 
	if (str1[m - 1] == str2[n - 1]) 
		return editDist(str1, str2, m - 1, n - 1); 

	// If last characters are not same, consider all three 
	// operations on last character of first string, recursively 
	// compute minimum cost for all three operations and take 
	// minimum of three values. 
	return 1 + min(editDist(str1, str2, m, n - 1), // Insert 
				editDist(str1, str2, m - 1, n), // Remove 
				editDist(str1, str2, m - 1, n - 1) // Replace 
				); 
} 

int editDistDP(string str1, string str2, int m, int n) 
{ 
    // Create a table to store results of subproblems 
    int dp[m + 1][n + 1]; 
  
    // Fill d[][] in bottom up manner 
    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            // If first string is empty, only option is to 
            // insert all characters of second string 
            if (i == 0) 
                dp[i][j] = j; // Min. operations = j 
  
            // If second string is empty, only option is to 
            // remove all characters of second string 
            else if (j == 0) 
                dp[i][j] = i; // Min. operations = i 
  
            // If last characters are same, ignore last char 
            // and recur for remaining string 
            else if (str1[i - 1] == str2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1]; 
  
            // If the last character is different, consider all 
            // possibilities and find the minimum 
            else
                dp[i][j] = 1 + min(dp[i][j - 1], // Insert 
                                   dp[i - 1][j], // Remove 
                                   dp[i - 1][j - 1]); // Replace 
        } 
    } 
  
    return dp[m][n]; 
}


void EditDistDP2(string str1, string str2) 
{ 
    int len1 = str1.length(); 
    int len2 = str2.length(); 
  
    // Create a DP array to memoize result 
    // of previous computations 
    int DP[2][len1 + 1]; 
  
    // To fill the DP array with 0 
    memset(DP, 0, sizeof DP); 
  
    // Base condition when second string 
    // is empty then we remove all characters 
    for (int i = 0; i <= len1; i++) 
        DP[0][i] = i; 
  
    // Start filling the DP 
    // This loop run for every 
    // character in second string 
    for (int i = 1; i <= len2; i++) { 
        // This loop compares the char from 
        // second string with first string 
        // characters 
        for (int j = 0; j <= len1; j++) { 
            // if first string is empty then 
            // we have to perform add character 
            // operation to get second string 
            if (j == 0) 
                DP[i % 2][j] = i; 
  
            // if character from both string 
            // is same then we do not perform any 
            // operation . here i % 2 is for bound 
            // the row number. 
            else if (str1[j - 1] == str2[i - 1]) { 
                DP[i % 2][j] = DP[(i - 1) % 2][j - 1]; 
            } 
  
            // if character from both string is 
            // not same then we take the minimum 
            // from three specified operation 
            else { 
                DP[i % 2][j] = 1 + min(DP[(i - 1) % 2][j], 
                                       min(DP[i % 2][j - 1], 
                                           DP[(i - 1) % 2][j - 1])); 
            } 
        } 
    } 
  
    // after complete fill the DP array 
    // if the len2 is even then we end 
    // up in the 0th row else we end up 
    // in the 1th row so we take len2 % 2 
    // to get row 
    cout << DP[len2 % 2][len1] << endl; 
}


//**some bug in top down dp wrong anser

int editDist_td(string str1, string str2, int m, int n, int dp[][maximum]) 
{ 
    // If first string is empty, the only option is to 
    // insert all characters of second string into first 
    if (m == 0) 
        return n; 
  
    // If second string is empty, the only option is to 
    // remove all characters of first string 
    if (n == 0) 
        return m; 
  
    // if the recursive call has been 
    // called previously, then return 
    // the stored value that was calculated 
    // previously 
    if (dp[m - 1][n - 1] != -1) 
        return dp[m - 1][n - 1]; 
  
    // If last characters of two strings are same, nothing 
    // much to do. Ignore last characters and get count for 
    // remaining strings. 
  
    // Store the returned value at dp[m-1][n-1] 
    // considering 1-based indexing 
    if (str1[m - 1] == str2[n - 1]) 
        return dp[m - 1][n - 1] = editDist_td(str1, str2, m - 1, n - 1, dp); 
  
    // If last characters are not same, consider all three 
    // operations on last character of first string, recursively 
    // compute minimum cost for all three operations and take 
    // minimum of three values. 
  
    // Store the returned value at dp[m-1][n-1] 
    // considering 1-based indexing 
    return dp[m - 1][n - 1] = 1 + min(editDist_td(str1, str2, m, n - 1, dp), // Insert 
                                      editDist_td(str1, str2, m - 1, n, dp), // Remove 
                                      editDist_td(str1, str2, m - 1, n - 1, dp) // Replace 
                                      ); 
}  


 

// Driver program 
int main() 
{ 
	// your code goes here 
	string str1 = "sunday"; 
	string str2 = "saturday"; 

	cout << editDist(str1, str2, str1.length(), str2.length()) << "\n"; 
	EditDistDP2(str1,str2); 
	
	int m = str1.length(); 
    int n = str2.length(); 
  
    // Declare a dp array which stores 
    // the answer to recursive calls 
    int dp[m][maximum]; 
  
    // initially all index with -1 
	//memset(dp, -1, sizeof dp); 
  //cout << editDist_td(str1, str2, m, n, dp); 

	return 0; 
} 









/*related question
 * https://www.geeksforgeeks.org/print-all-possible-ways-to-convert-one-string-into-another-string-edit-distance/?ref=rp
 * https://www.geeksforgeeks.org/edit-distance-and-lcs-longest-common-subsequence/?ref=rp
 * 
 * There are other popular measures of edit distance, which are calculated using a different set of allowable edit operations. For instance,

    the Damerau–Levenshtein distance allows the transposition of two adjacent characters alongside insertion, deletion, substitution;
    the longest common subsequence (LCS) distance allows only insertion and deletion, not substitution;
    the Hamming distance allows only substitution, hence, it only applies to strings of the same length.
    the Jaro distance allows only transposition.
    */ 
