//more optimise solution:https://www.hackerrank.com/contests/moodys-analytics-fall-university-codesprint/challenges/tile-stacking-problem/editorial 
#include<bits/stdc++.h> 
using namespace std; 

int maxRevenue(int m, int x[], int revenue[], int n, 
											int t) 
{ 
	// Array to store maximum revenue at each miles. 
	int maxRev[m+1]; 
	memset(maxRev, 0, sizeof(maxRev)); 

	// actual minimum distance between 2 billboards. 
	int nxtbb = 0; 
	for (int i = 1; i <= m; i++) 
	{ 
		// check if all billboards are already placed. 
		if (nxtbb < n) 
		{ 
			// check if we have billboard for that particular 
			// mile. If not, copy the previous maximum revenue. 
			if (x[nxtbb] != i) 
				maxRev[i] = maxRev[i-1]; 

			// we do have billboard for this mile. 
			else
			{ 
				// We have 2 options, we either take current 
				// or we ignore current billboard. 

				// If current position is less than or equal to 
				// t, then we can have only one billboard. 
				if (i <= t) 
					maxRev[i] = max(maxRev[i-1], revenue[nxtbb]); 

				// Else we may have to remove previously placed 
				// billboard 
				else
					maxRev[i] = max(maxRev[i-t-1]+revenue[nxtbb], 
												maxRev[i-1]); 

				nxtbb++; 
			} 
		} 
		else
			maxRev[i] = maxRev[i - 1]; 
	} 

	return maxRev[m]; 
} 

// Driven Program 
int main() 
{ 
	int m = 20; 
	int x[] = {6, 7, 12, 13, 14}; 
	int revenue[] = {5, 6, 5, 3, 1}; 
	int n = sizeof(x)/sizeof(x[0]); 
	int t = 5; 
	cout << maxRevenue(m, x, revenue, n, t) << endl; 
	return 0; 
} 
