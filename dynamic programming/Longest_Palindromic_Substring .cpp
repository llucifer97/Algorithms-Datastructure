/*https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
 * approach1: brute force{O(n^3)}
 * approach2: Dynamic programming   : Time complexity: O ( n^2 ) Auxiliary Space: O ( n^2 ) 
 * approach3: space optimised Time complexity: O ( n^2 ) where n is the length of input string. Auxiliary Space: O ( 1 )
 * approach4:Longest Palindromic Substring using Palindromic Tree  :https://www.geeksforgeeks.org/longest-palindromic-substring-using-palindromic-tree-set-3/?ref=rp
 * using recursion:https://www.geeksforgeeks.org/length-of-longest-palindromic-sub-string-recursion/?ref=rp
 * approach5:manchester algorithm : https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/?ref=rp
 * approach6:suffix tree - linear [O(n)] : https://www.geeksforgeeks.org/suffix-tree-application-6-longest-palindromic-substring/?ref=rp
 */


#include <bits/stdc++.h> 
using namespace std; 


// Function to print a substring str[low..high] 
void printSubStr( string str, int low, int high ) 
{ 
	for( int i = low; i <= high; ++i ) 
		cout << str[i]; 
} 

// This function prints the longest palindrome substring 
// It also returns the length of the longest palindrome 
int longestPalSubstr(string str) 
{ 
	// get length of input string 
	int n = str.size(); 

	// table[i][j] will be false if substring str[i..j] 
	// is not palindrome. 
	// Else table[i][j] will be true 
	bool table[n][n]; 
	
	memset(table, 0, sizeof(table)); 

	// All substrings of length 1 are palindromes 
	int maxLength = 1; 
	
	for (int i = 0; i < n; ++i) 
		table[i][i] = true; 

	// check for sub-string of length 2. 
	int start = 0; 
	for (int i = 0; i < n-1; ++i) 
	{ 
		if (str[i] == str[i+1]) 
		{ 
			table[i][i+1] = true; 
			start = i; 
			maxLength = 2; 
		} 
	} 

	// Check for lengths greater than 2. k is length 
	// of substring 
	for (int k = 3; k <= n; ++k) 
	{ 
		// Fix the starting index 
		for (int i = 0; i < n-k+1 ; ++i) 
		{ 
			// Get the ending index of substring from 
			// starting index i and length k 
			int j = i + k - 1; 

			// checking for sub-string from ith index to 
			// jth index iff str[i+1] to str[j-1] is a 
			// palindrome 
			if (table[i+1][j-1] && str[i] == str[j]) 
			{ 
				table[i][j] = true; 

				if (k > maxLength) 
				{ 
					start = i; 
					maxLength = k; 
				} 
			} 
		} 
	} 

cout << "Longest palindrome substring is: "; 
printSubStr( str, start, start + maxLength - 1 ); 
	
	// return length of LPS 
	return maxLength; 
}


int longestPalSubstr2(char *str)  
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

// Driver Code 
int main() 
{ 
	string str = "forgeeksskeegfor"; 
	cout << "\nLength is: " << longestPalSubstr( str ); 
	cout << "\n";
	char str2[] = "forgeeksskeegfor";  
    cout<<"\nLength is: "<<longestPalSubstr(str2)<<endl;
	return 0; 
} 






//related question
/*
 * https://www.geeksforgeeks.org/maximum-length-palindromic-substring-such-that-it-starts-and-ends-with-given-char/?ref=rp
 * https://www.geeksforgeeks.org/length-of-the-longest-substring-that-do-not-contain-any-palindrome/?ref=rp
 * https://www.geeksforgeeks.org/longest-palindromic-string-possible-after-removal-of-a-substring/?ref=rp
 * https://www.geeksforgeeks.org/longest-non-palindromic-substring/?ref=rp
 * https://www.geeksforgeeks.org/palindromic-tree-introduction-implementation/?ref=rp
 * https://www.geeksforgeeks.org/make-palindromic-string-non-palindromic-by-rearranging-its-letters/?ref=rp
 * 
 * 
 */ 












