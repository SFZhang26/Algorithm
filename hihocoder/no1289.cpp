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

struct Node {
	int decision;
	Node *zero;
	Node *one;

	Node(int d) {
		decision = d;
		zero = NULL;
		one = NULL;
	}
};


string getString(string s) {
	string res = "";
	s = s + '.';
	int start = 0;
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.' || s[i] == '/') {
			int num = atoi(s.substr(start, i - start).c_str());
			if (count < 4) {
				bitset<8> b(num);
				res += b.to_string();
				count++;
			}
			else {
				res = res.substr(0, num);
			}
			start = i + 1;
		}
	}
	return res;
}

void addNode(Node *parent, int decision, string s, int index) {
	if (s.size() <= index) {
		if (parent->decision == 0) parent->decision = decision;
		return;
	}
	if (parent->decision != 0) return;

	if (s[index] == '1') {
		if (parent->one == NULL) {
			Node *next = new Node(0);
			parent->one = next;
		}
		parent = parent->one;
	}
	else {
		if (parent->zero == NULL) {
			Node *next = new Node(0);
			parent->zero = next;
		}
		parent = parent->zero;
	}
	addNode(parent, decision, s, index + 1);
}

bool query(Node *root, string s) {
	int des = 0;
	int i = 0;
	while (i<s.size()) {
		if (root->decision != 0) des = root->decision;
		if (s[i] == '1') {
			if (root->one == NULL) return des >= 0;
			else root = root->one;
		}
		else {
			if (root->zero == NULL) return des >= 0;
			else root = root->zero;
		}
		i++;
	}
	des = root->decision;
	return des >= 0;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int i1, i2, i3, i4, count;
	char ch, deci[10];
	Node *root = new Node(0);
	for (int i = 0; i < n; i++) {
		count = 32;
		scanf("%s %d.%d.%d.%d", deci, &i1, &i2, &i3, &i4);
		scanf("%c", &ch);
		if (ch == '/') scanf("%d", &count);
		ll num = (i1 << 24) + (i2 << 16) + (i3 << 8) + i4;
		bitset<32> b(num);
		string cur = b.to_string().substr(0, count);
		int decision = strcmp(deci, "allow") == 0 ? 1 : -1;
		addNode(root, decision, cur, 0);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d.%d.%d.%d", &i1, &i2, &i3, &i4);
		ll num = (i1 << 24) + (i2 << 16) + (i3 << 8) + i4;
		bitset<32> b(num);
		string cur = b.to_string();
		bool res = query(root, cur);
		if (res) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}