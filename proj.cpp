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

string dict [] = { "i", "me", "you", "us", "we", "he", "she", "him", "her", "it", "they", "them" };

void create_database(){
	int len = sizeof(dict) / sizeof(dict[0]);
	for (int i = 0; i < len; i++){
		trie_insert (dict[i]);
	}
}

int main() {
	//fast_and_furious();
	freopen("input.txt", "r", stdin);
	create_database();
	cout<<trie_search("she")<<" "<<trie_search("a")<<" "<<trie_search("i")<<" "<<trie_search("mukul");
	return 0;
}
