#include <iostream>
using namespace std;
int givetrueHelper(string s,int i,int j,bool isTrue)
{
    if (i > j)
		return false;
    if(i==j)
    {
        if(isTrue){
            return s[i] == 'T';
        }else{
            return s[i] == 'F';
        }
    }

	
	
    int ans = 0;

    for(int k = i + 1;k<=j-1;k = k + 2)
    {
        int leftTrue = givetrueHelper(s,i,k-1,1);
        int lefFalse = givetrueHelper(s,i,k-1,0);
        int rightTrue = givetrueHelper(s,k+1,j,1);
        int rightFalse = givetrueHelper(s,k + 1,j,0);
        
         if(s[k] == '&')
         {
			 if(isTrue){
				 ans += leftTrue*rightTrue;
			 }else{
				 ans += rightTrue*lefFalse  + rightFalse*leftTrue + rightFalse*lefFalse;
			 }
             
         }
         else if(s[k] == '|'){
			 if(isTrue)
			 {
				 ans += rightTrue*lefFalse  + rightFalse*leftTrue + leftTrue*rightTrue;
			 }else{
				 ans += lefFalse*rightFalse;
			 }
             
         }else if(s[k] == '^'){
			 if(isTrue)
			 {
				  ans += rightTrue*lefFalse  + rightFalse*leftTrue;
			 }else{
				 ans +=  leftTrue*rightTrue + lefFalse*rightFalse;
			 }
            
         }
    }
    
   
    return ans;
    
}

int givetrue(int n,string s)
{
    return givetrueHelper(s,0,n-1,1);
    
}


int main() {
	
	

			string s = "T|T&F^T";
			int n = s.size();
		 
	    cout << givetrue(n,s) << "\n";

	return 0;
}











