/*https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
 * https://www.geeksforgeeks.org/print-longest-palindromic-subsequence/
 * Approach1:brute force time omplexity{O(n^3)}
 * Approach2: recursive implementation
 * approach3: tabulation bottom up time complexity{O(n^2))}
 * approach4: space optimised {O(n)} time complexity{O(n^2)}
 * approach5: O(n^2) time and O(1) space 
 * 
 */

#include<bits/stdc++.h> 
using namespace std; 

// A utility function to get max of two integers 
int max (int x, int y) { return (x > y)? x : y; } 

// Returns the length of the longest palindromic subsequence in seq 
int lps(char *seq, int i, int j) 
{ 
// Base Case 1: If there is only 1 character 
if (i == j) 
	return 1; 

// Base Case 2: If there are only 2 
// characters and both are same 
if (seq[i] == seq[j] && i + 1 == j) 
	return 2; 

// If the first and last characters match 
if (seq[i] == seq[j]) 
	return lps (seq, i+1, j-1) + 2; 

// If the first and last characters do not match 
return max( lps(seq, i, j-1), lps(seq, i+1, j) ); 
} 




//bootom up
// Returns the length of the longest palindromic subsequence in seq 
int lps_bu(char *str) 
{ 
   int n = strlen(str); 
   int i, j, cl; 
   int L[n][n];  // Create a table to store results of subproblems 
  
  
   // Strings of length 1 are palindrome of lentgh 1 
   for (i = 0; i < n; i++) 
      L[i][i] = 1; 
  
    // Build the table. Note that the lower diagonal values of table are 
    // useless and not filled in the process. The values are filled in a 
    // manner similar to Matrix Chain Multiplication DP solution (See 
    // https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/). cl is length of 
    // substring 
    for (cl=2; cl<=n; cl++) 
    { 
        for (i=0; i<n-cl+1; i++) 
        { 
            j = i+cl-1; 
            if (str[i] == str[j] && cl == 2) 
               L[i][j] = 2; 
            else if (str[i] == str[j]) 
               L[i][j] = L[i+1][j-1] + 2; 
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]); 
        } 
    } 
    
    
    
  
    return L[0][n-1]; 
} 

//space optimised
// Returns the length of the longest palindromic 
// subsequence in str 
int lps(string &s) 
{ 
    int n = s.length(); 
  
    // a[i] is going to store length of longest 
    // palindromic subsequence of substring s[0..i] 
    int a[n]; 
  
    // Pick starting point 
    for (int i = n - 1; i >= 0; i--) { 
  
        int back_up = 0; 
          
  
        // Pick ending points and see if s[i] 
        // increases length of longest common 
        // subsequence ending with s[j]. 
        for (int j = i; j < n; j++) { 
  
            // similar to 2D array L[i][j] == 1 
            // i.e., handling substrings of length 
            // one. 
            if (j == i) 
                a[j] = 1;  
  
            // Similar to 2D array L[i][j] = L[i+1][j-1]+2 
            // i.e., handling case when corner characters 
            // are same.  
            else if (s[i] == s[j]) 
            { 
                  
                // value a[j] is depend upon previous  
                // unupdated value of a[j-1] but in  
                // previous loop value of a[j-1] is  
                // changed. To store the unupdated  
                // value of a[j-1] back_up variable  
                // is used. 
                int temp = a[j]; 
                a[j] = back_up + 2; 
                back_up = temp; 
            } 
  
            // similar to 2D array L[i][j] = max(L[i][j-1], 
            // a[i+1][j]) 
            else
            { 
                back_up = a[j]; 
                a[j] = max(a[j - 1], a[j]); 
            } 
        } 
    } 
      
    return a[n - 1]; 
} 

// A utility function to print a substring str[low..high]  
void printSubStr(char* str, int low, int high)  
{  
    for( int i = low; i <= high; ++i )  
        cout << str[i];  
}  
  
// This function prints the longest palindrome substring (LPS)  
// of str[]. It also returns the length of the longest palindrome  
int longestPalSubstr(char *str)  
{  
    int maxLength = 1; // The result (length of LPS)  
  
    int start = 0;  
    int len = strlen(str);  
  
    int low, high;  
  
    // One by one consider every character as center point of  
    // even and length palindromes  
    for (int i = 1; i < len; ++i)  
    {  
        // Find the longest even length palindrome  
        // with center points as i-1 and i.  
        low = i - 1;  
        high = i;  
        while (low >= 0 && high < len && str[low] == str[high])  
        {  
            if (high - low + 1 > maxLength)  
            {  
                start = low;  
                maxLength = high - low + 1;  
            }  
            --low;  
            ++high;  
        }  
  
        // Find the longest odd length palindrome with center  
        // point as i  
        low = i - 1;  
        high = i + 1;  
        while (low >= 0 && high < len && str[low] == str[high])  
        {  
            if (high - low + 1 > maxLength)  
            {  
                start = low;  
                maxLength = high - low + 1;  
            }  
            --low;  
            ++high;  
        }  
    }  
  
    cout<<"Longest palindrome substring is: ";  
    printSubStr(str, start, start + maxLength - 1);  
  
    return maxLength;  
}  
  




/* Driver program to test above functions */
int main() 
{ 
	char seq[] = "GEEKSFORGEEKS"; 
	int n = strlen(seq); 
	cout << "The length of the LPS is "<< lps(seq, 0, n-1); 
		cout << "\n";
	cout << "The length of the LPS_bu is "<< longestPalSubstr(seq); 
	return 0; 
} 
