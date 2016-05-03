//Author: Mukul Chandel
#include<bits/stdc++.h>

using namespace std;

inline void fast_and_furious() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
}

class node {
	public:
		bool isleaf;
		class node *child[26];
		node () {
			isleaf = false;
		}
} *root = new node;

void trie_insert (string s) {
	node *current = root;
	for (int i = 0; i < s.length(); i++) {
		int letter = s[i] - 'a';
		if( current-> child[letter] == NULL ) {
			current-> child[letter] = new node;
		}
		current = current-> child[letter];
	}
	current-> isleaf = true;
}

bool trie_search (string s) {
	node *current = root;
	for (int i = 0; i < s.length(); i++){
		int letter = s[i] - 'a';
		if( current-> child[letter] == NULL ) {
			return false;
		}
		current = current-> child[letter];
	}
	return current-> isleaf;
}

string dict [] = { "i", "me", "you", "us", "we", "he", "she", "him", "her", "it", "they", "them", "to", "and", "in", "the", "a" };

void create_database(){
	int len = sizeof(dict) / sizeof(dict[0]);
	for (int i = 0; i < len; i++){
		trie_insert (dict[i]);
	}
}

bool special (char x) {
	switch(x){
		case ' ' : return 1;
		case '.' : return 1;
		case ',' : return 1;
		case '!' : return 1;
		case '\0' : return 1;
		case '\n' : return 1;
		case '\t' : return 1;
		default : return 0;
	}
}

void remove_tokens (string& input) {
	for(int i = 0; i < input.length(); i++) {
		if( !special(input[i]) ) {
			int j=i;
			while( !special(input[j]) ) j++;
			if( trie_search( input.substr(i,j-i) ) ) input.erase(i, j-i);
			else i=j-1;
		}
	}
}

int main() {
	//fast_and_furious();
	freopen ("input.txt", "r", stdin);
	create_database();
	string input;
	getline (cin,input,'\0');
	cout<<"Before : "<<input<<"\n";
	remove_tokens (input);
	cout<<"After : "<<input<<"\n";
	return 0;
}
