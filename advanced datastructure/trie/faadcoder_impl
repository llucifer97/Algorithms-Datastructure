#include<bits/stdc++.h>
using namespace std;
#define ll long long int


struct trie{
	struct trie *child[26];
	bool isend;

	trie()
	{
		memset(child,0,sizeof(child));
		isend=false;
	}

};



struct trie2{
	bool isend;
	unordered_map<char,trie2*> mp;

	trie2()
	{
		isend=false;
	}

};




struct trie *root;

struct trie2* root1;



void insert2(string str)
{
	struct trie2* cur=root1;
	for(char ch:str)
	{
		if(!cur->mp.count(ch))
			cur->mp[ch]=new trie2;
		cur=cur->mp[ch];
	}
	cur->isend=true;
}

bool search2(string str)
{
	struct trie2* cur=root1;
	for(char ch:str)
	{
		if(!cur->mp.count(ch))
			return false;
		cur=cur->mp[ch];
	}
	return cur->isend;
}






void insert(string str)
{
	struct trie *cur=root;
	for(char ch:str)
	{
		int idx=ch-'a';
		if(cur->child[idx]==NULL)
		{
			cur->child[idx]=new trie;
		}
		cur=cur->child[idx];
	}
	cur->isend=true;
}


bool search(string str)
{
	struct trie *cur=root;
	for(char ch:str)
	{
		int idx=ch-'a';
		if(cur->child[idx]==NULL)
			return false;
		cur=cur->child[idx];
	}
	return cur->isend;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	root=new trie;

	root1=new trie2;

	ll n;
	cin>>n;
	while(n--)
	{
		string str;
		cin>>str;
		insert2(str);
	}
	cin>>n;
	while(n--)
	{
		string str;
		cin>>str;
		if(search2(str))
		{
			cout<<str<<" is present\n";
		}
		else
		{
			cout<<str<<" is not present\n";
		}
	}

}
