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
		class node *child[27];
		node () {
			isleaf = false;
		}
} *root = new node;

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

void trie_insert (string s) {
	node *current = root;
	for (int i = 0; i < s.length(); i++) {
		int letter = tolower(s[i]) - 'a';
		letter = (letter == -65) ? 26 : letter;
		if( current-> child[letter] == NULL ) {
			current-> child[letter] = new node;
		}
		current = current-> child[letter];
	}
	current-> isleaf = true;
}

pair< bool, int > trie_search (string s, int start) {
	node *current = root;
	int i = start, letter = tolower(s[start]) - 'a';
	letter = (letter == -65) ? 26 : letter;
	while (current-> child[letter] != NULL){
		current = current-> child[letter];
		i++;
		letter = tolower(s[i]) - 'a';
		letter = (letter == -65) ? 26 : letter;
	}
	return make_pair( ( current-> isleaf && special (s[i]) ), i );
}

string dict [] = {
	"i", "me", "my", "you", "us", "we", "he", "she","him", "her",
	"it", "they", "them", "to", "and", "in", "the", "a",
	"according to", "along with", "alongside", "among", "apart from",
	"as for", "atop", "because of", "by means of", "concerning",
	"despite", "except for", "in addition to", "in back of",
	"in case of", "in front of", "in place of", "in spite of",
	"instead of", "on top of", "out of", "regarding", "throughout",
	"till", "up to", "via", "within", "worth"
};

void create_database(){
	int len = sizeof(dict) / sizeof(dict[0]);
	for (int i = 0; i < len; i++)	trie_insert (dict[i]);
}

void remove_tokens (string& input) {
	pair< bool, int > res;
	for(int i = 0; i < input.length(); i++) {
		if( !special(input[i]) ) {
			res = trie_search (input, i);
			if ( res.first ) while (i < res.second)	input[i++] = '-';
			i = res.second;
			while (!special(input[i]) )	i++;
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
	cout<<"After  : "<<input<<"\n";
	return 0;
}
