#include <bits/stdc++.h>
using namespace std;



typedef vector<int> vi;
typedef vector< vi > vvi;


class comparefunc{
public:
    bool operator()(int a, int b){
        if(a<b){
            return true;
        }
        return false;
    }
};

bool compare(int a , int b){
    if(a<b){
        return true;
    }
    return false;
}

void func(vi &vv){
    cout<<"lambda function "<<endl;
    vi v(vv.begin(), vv.end());
    sort(v.begin(), v.end(), [](int a, int b){
        if(a<b){
            return true;
        }
        return false;
    });
    for(int i=0; i<v.size(); ++i){
        cout<<v[i]<<" ";
    }
    cout<<"\nOperator call function "<<endl;
    vi v1(vv.begin(), vv.end());
    sort(v1.begin(), v1.end(), comparefunc());
    for(int i=0; i<v1.size(); ++i){
        cout<<v1[i]<<" ";
    }
    cout<<"\nnormal function "<<endl;
    vi v2(vv.begin(), vv.end());
    sort(v2.begin(), v2.end(), compare);
    for(int i=0; i<v2.size(); ++i){
        cout<<v2[i]<<" ";
    }
    //fourth one which is by default used from header function
    cout<<"\nfrom function header "<<endl;
    vi v3(vv.begin(), vv.end());
    //by default for ascending order less<int>() from function header is used
    sort(v3.begin(), v3.end(), less<int>());
    for(int i=0; i<v3.size(); ++i){
        cout<<v3[i]<<" ";
    }
    cout<<"\nfor descending order "<<endl;
    sort(v3.begin(), v3.end(), greater<int>());
    for(int i=0; i<v3.size(); ++i){
        cout<<v3[i]<<" ";
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    //code part
    //solve here
    vi v{2, 4, 6, 3, 8, 5};
    func(v);






	return 0;
}

