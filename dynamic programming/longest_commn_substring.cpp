/* Dynamic Programming solution to find length of the 
longest common substring */
/* APPROACH1:iterative implementation(bottom up){complexity:O(m*n)}
 * APPROACH2 :recursion
 * APPROACH3 : top down memoization(to be implemented)** :https://stackoverflow.com/questions/30859547/dp-memoized-approach-for-longest-common-substring  (reference)
 * APPROACH4:space optimization
 * The following tricks can be used to reduce the memory usage of an implementation:more room for space optimization

    Keep only the last and current row of the DP table to save memory ( O ( min ( r , n ) ) {\displaystyle O(\min(r,n))} {\displaystyle O(\min(r,n))} instead of O ( n r ) {\displaystyle O(nr)} {\displaystyle O(nr)})
    Store only non-zero values in the rows. This can be done using hash tables instead of arrays. This is useful for large alphabets.
    
 * APPROACH5:using suffix tree {O(n + m) time complexity}  : https://www.geeksforgeeks.org/suffix-tree-application-5-longest-common-substring-2/
 */
#include <bits/stdc++.h>

using namespace std; 

/* Returns length of longest common substring of X[0..m-1] 
and Y[0..n-1] */
char X[] = "OldSite:GeeksforGeeks.org"; 
char Y[] = "NewSite:GeeksQuiz.com"; 
string x,y;
int LCSubStr(char *X, char *Y, int m, int n) 
{ 
	// Create a table to store lengths of longest 
	// common suffixes of substrings. Note that 
	// LCSuff[i][j] contains length of longest 
	// common suffix of X[0..i-1] and Y[0..j-1]. 

	int LCSuff[m+1][n+1]; 
	int result = 0; // To store length of the 
					// longest common substring 

	/* Following steps build LCSuff[m+1][n+1] in 
		bottom up fashion. */
	for (int i=0; i<=m; i++) 
	{ 
		for (int j=0; j<=n; j++) 
		{ 

			// The first row and first column 
			// entries have no logical meaning, 
			// they are used only for simplicity 
			// of program 
			if (i == 0 || j == 0) 
				LCSuff[i][j] = 0; 

			else if (X[i-1] == Y[j-1]) 
			{ 
				LCSuff[i][j] = LCSuff[i-1][j-1] + 1; 
				result = max(result, LCSuff[i][j]); 
			} 
			else LCSuff[i][j] = 0; 
		} 
	} 
	return result; 
} 


int lcs(int i, int j, int count)  
{ 
      
    if (i == 0 || j == 0) 
        return count; 
          
    if (X[i-1] == Y[j-1]) { 
        count = lcs(i - 1, j - 1, count + 1); 
    } 
        count = max(count, max(lcs( i, j - 1, 0), lcs( i - 1, j, 0))); 
    return count; 
} 

int lcss_topdown(string x,string y){
	//to be implemented
	return 0;
	}
int LCSubStr_spaceopt(string X, string Y) 
{ 
    // Find length of both the strings. 
    int m = X.length(); 
    int n = Y.length(); 
  
    // Variable to store length of longest 
    // common substring. 
    int result = 0; 
  
    // Matrix to store result of two 
    // consecutive rows at a time. 
    int len[2][n]; 
  
    // Variable to represent which row of 
    // matrix is current row. 
    int currRow = 0; 
  
    // For a particular value of i and j, 
    // len[currRow][j] stores length of longest 
    // common substring in string X[0..i] and Y[0..j]. 
    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            if (i == 0 || j == 0) { 
                len[currRow][j] = 0; 
            } 
            else if (X[i - 1] == Y[j - 1]) { 
                len[currRow][j] = len[1 - currRow][j - 1] + 1; 
                result = max(result, len[currRow][j]); 
            } 
            else { 
                len[currRow][j] = 0; 
            } 
        } 
  
        // Make current row as previous row and previous 
        // row as new current row. 
        currRow = 1 - currRow; 
    } 
  
    return result; 
} 

/* Driver program to test above function */
int main() 
{ 
	

	int m = strlen(X); 
	int n = strlen(Y); 

	cout << "Length of Longest Common Substring is "	<< LCSubStr(X, Y, m, n); 
		x = "abcdxyz";  
		y = "xyzabcd"; 
  cout << "\n";
int n_x=x.size(); 
int m_y=y.size(); 
	
  cout<<lcs(n_x,m_y,0); 
    cout << "\n";

  cout << LCSubStr_spaceopt(x,y);
  cout << "\n";
  
	return 0; 
} 
