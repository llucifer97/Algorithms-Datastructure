// stack using recursion 
#include<bits/stdc++.h> 
using namespace std; 


    stack<int> st;
    
    void insert_at_bottom(int curr)
    {
        if(st.empty())   //stack is empty means bottom of the stack,insert the current element
            st.push(curr);
        else
        {
            int el=st.top();
            st.pop();
            insert_at_bottom(curr);
            st.push(el);
        }
    }
    void reverse()
    {
        if(st.empty())
            return;
        int d=st.top();
        st.pop();
        reverse();
        insert_at_bottom(d); //Inserting an element at bottom of the stack.
    }





int main() 
{ 
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	reverse();
	while(!st.empty()){
		cout << st.top() << "\n";
		st.pop();
		}
	return 0; 
} 
