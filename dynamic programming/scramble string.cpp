// Scramble String : https://leetcode.com/problems/scramble-string/

/*
We can scramble a string s to get a string t using the following algorithm:

1. If the length of the string is 1, stop.
2. If the length of the string is > 1, do the following:
    a.  Split the string into two non-empty substrings at a 
        random index, i.e., if the string is s, divide it to x and y where s = x + y.
    b.  Randomly decide to swap the two substrings or to keep them in the 
        same order. i.e., after this step, s may become s = x + y or s = y + x.
    c.  Apply step 1 recursively on each of the two substrings x and y.

Given two strings s1 and s2 of the same length, return true if 
s2 is a scrambled string of s1, otherwise, return false.

*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> dp;

bool solve(string s1, string s2) {
    string p = s1 + s2;

    if (dp.count(p))
        return dp[p];

    // base case1
    if (s1 == s2)
        return dp[p] = true;

    // base case2: if s1 and s2 arent anagrams then return false
    int len = s1.length();
    int count[26] = {0};

    for (int i = 0; i < len; i++) {
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
        if (count[i] != 0)
            return dp[p] = false;

    // base case check complete


    for (int i = 1; i <= s1.length() - 1; i++) {
        if (solve(s1.substr(0, i), s2.substr(0, i)) and solve(s1.substr(i), s2.substr(i)))
            return dp[p] = true;

        if (solve(s1.substr(0, i), s2.substr(s2.length() - i)) and solve(s1.substr(i), s2.substr(0, s2.length() - i)))
            return dp[p] = true;
    }

    return dp[p] = false;
}

bool isScramble(const string A, const string B) {
    dp.clear();
    return solve(A, B);
}


int main() {
    
    string s, t;
    cin >> s >> t;
    cout << isScramble(s, t);

    return 0;
}