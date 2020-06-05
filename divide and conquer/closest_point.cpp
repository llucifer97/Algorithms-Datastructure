//Input: points = [[1,3],[-2,2]], K = 1
//Output: [[-2,2]]
//method1--priority queue
/*
class Solution {
public:
     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        if(points.size()==0)return ans;
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<points.size();i++)
        {
            int dist=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            if(pq.size()<k)
            pq.push({dist,{points[i][0],points[i][1]}});
            else
            {
                if(dist<pq.top().first)
                {
                    pq.pop();
                    pq.push({dist,{points[i][0],points[i][1]}});
                }
            }
        }
        while(!pq.empty())
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};
*/

//method2:divide and conquer
#include<bits/stdc++.h> 
using namespace std;
//https://leetcode.com/problems/k-closest-points-to-origin/solution/
//quicselect + megesort
   
// Driver program to test above functions 
int main() 
{ 
	Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}; 
	int n = sizeof(P) / sizeof(P[0]); 
	cout << "The smallest distance is " << closest(P, n); 
	return 0; 
} 












