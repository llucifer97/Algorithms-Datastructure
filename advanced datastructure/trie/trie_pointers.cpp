#include <bits/stdc++.h>
using namespace std;              


struct Trie{

	char data;
	Trie *children[26];
	bool endofword;

};

Trie* getNode(){
	Trie* pcrawl = new Trie;
	pcrawl->endofword = false;

	for(int i =0;i<26;i++){
		pcrawl->children[i] = nullptr;
	}
	return pcrawl;
}

Trie* insert(string key,Trie *root){

	Trie* pcrawl = root;

	
	for(int i = 0;i<key.size();i++){
		int index = key[i] - 'a';
		if(!pcrawl->children[index]){
			pcrawl->children[index] = getNode();
		}
		  pcrawl =  pcrawl->children[index];
	}

		pcrawl->endofword = true;

		return pcrawl;

}

bool search(string key,Trie* root) {

	Trie* pcrawl = root;

	
	for(int i = 0;i<key.size();i++){
		int index = key[i] - 'a';
		if(!pcrawl->children[index]){
			return false;
		}
		  pcrawl =  pcrawl->children[index];
	}

		
	return (pcrawl && pcrawl->endofword);

}

void Delete(string key,Trie* root){

	Trie* pcrawl = root;

	for(int i = 0;i<key.size();i++){
		int index = key[i] - 'a';
		if(!pcrawl->children[index]){
			continue;
		}
		  pcrawl =  pcrawl->children[index];
	}

	if(pcrawl && pcrawl->endofword)
		pcrawl->endofword = false;
		
}


int main(){

	 struct Trie *root = getNode(); 
	 insert("abab",root);

	 if(search("abab",root))
	 cout << " yeah its present!" << "\n";
	 Delete("abab",root);
	  cout << "yeah deleted it too!";
	 if(!search("abab",root)){
		 cout << "nah,not found!";
	 }
	return 0;
}
