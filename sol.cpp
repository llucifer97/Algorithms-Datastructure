// https://a.hirepro.in/dF7LDQ0O
// User Name: Qualcomm241743760563
// Password: 9BtrYQqu

#include<bits/stdc++.h>
using namespace std;

vector<string> vec;

void split(string str, char del){
      string temp = "";
   
      for(int i=0; i<(int)str.size(); i++){
       
         if(str[i] != del){
            temp += str[i];
        }
          else
          {
           vec.push_back(temp);
              temp = "";
        }
    }
       
}




int main()
{

    string s;
    cin >> s;
    int n = s.size();
      s += ",";
    split(s,',');

    string temp;

    for(int i = 0;i<vec.size();i++)
    {
        
        int x = stoi(vec[i]);
        int mn = x , j = 1;
       
        while(mn < pow(10,x))
        {
            if(x*j >= pow(10,x))
            {
                break;
            }
            mn = x*j;
            cout << mn << "\n";
            j++;
        }
        
        temp = temp + to_string(mn);
        if(i<vec.size()-1) temp += ",";


    }
    
    cout << temp;



    return 0;
}
