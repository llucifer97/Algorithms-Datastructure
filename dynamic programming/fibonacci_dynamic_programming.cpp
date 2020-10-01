#include <iostream>

using namespace std;

int fib(int n);


int memo[1000]; 		//this array keep track of the answers for the sub-problems

int main(){
		
	for(int i=0; i<100; i++){  		//initiate memo array with all indexes as zero values
		memo[i] = 0;
	}   
	
	cout << fib(9);
	
	return 0;
}

int fib(int n){
	if(n == 1 || n == 2){		//base case of the recursive algorithm
		return 1;
	}
	
	if(memo[n] != 0){			//checking whether the particular fib value  has been calculated earlier.
		return memo[n];			//if calculted, return the value (Avoid re-calculating the same sub-problem)
	}
	
	memo[n] = fib(n-1) + fib(n-2); 		//if not calculated before, calculate the value and save it for further usage
	return memo[n];
}
