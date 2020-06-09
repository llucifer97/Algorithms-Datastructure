https://www.geeksforgeeks.org/longest-subarray-not-k-distinct-elements/

#include<bits/stdc++.h> 
using namespace std; 


int maxsubarray(int a[],int n,int k){
	
	map<int,int> mp;
	int i =0,j =0;
	int maxarr = INT_MIN;
	if(n<=k){
		return n;
		}
	
	
	while(j<n){
		
		if(mp.size()<=k){
			
			mp[a[j]]++;
			maxarr = max(maxarr,j-i); 
			j++;
			}
		else{
			if(mp.find(a[i])!=mp.end()){
				mp.erase(a[i]);
				i++;
				
				}
			
			}
		
		
		
		}
	
	return maxarr;
	
	
	
	}



int main(){
	
	int arr[1] = {1};
	int k = 3;
	cout << maxsubarray(arr,1,k);
	
	return 0;
	}
