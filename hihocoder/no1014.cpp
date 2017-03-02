#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <map>
#include <string>
#include <bitset>
#include <set>

using namespace std;

typedef long long ll;

int T;

class TrieNode {
public:
	char val;
	bool isWord;
	TrieNode *children[26];
	ll count;
	TrieNode(){
		val = 0;
		isWord = false;
		for (int i = 0; i < 26; i++) children[i] = NULL;
		count = 0;
	}
	TrieNode(char c){
		val = c;
		isWord = false;
		for (int i = 0; i < 26; i++) children[i] = NULL;
		count = 0;
	}
};

class Trie{
public:
	TrieNode *root;
	Trie(){
		root = new TrieNode();
	}

	void insert(string word) {
		TrieNode* node = root;
		if (word.size() == 0) return;
		for (int i = 0; i < word.size(); i++) {
			char cur = word[i];
			if (node->children[cur - 'a']==NULL)
				node->children[cur - 'a'] = new TrieNode(cur);
			node->count++;
			node = node->children[cur - 'a'];
		}
		node->count++;
		node->isWord = true;
	}
	int search(string word) {
		TrieNode* node = root;
		if (word.size() == 0) return root->count;
		for (int i = 0; i < word.size(); i++) {
			char cur = word[i];
			if (node->children[cur - 'a'] == NULL)
				return 0;
			node = node->children[cur - 'a'];
		}
		return node->count;
	}
};

int main() {
	Trie tree;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		tree.insert(temp);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;
		cout << tree.search(temp) << endl;
	}

	return 0;
}