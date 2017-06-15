#include <cstdio>
#include <iostream>
#include <cstring>
#include <bitset> 

using namespace std;

typedef long long ll;

const int N = 2e6;

struct Trie {
	int root, total;
	int next[N][2], id[N];
	bool end[N];

	int NewNode() {
		memset(next[total], -1, sizeof(next[total]));
		return total++;
	}

	void init() {
		memset(id, 0, sizeof(id));
		total = 0;
		root = NewNode();
	}

	void insert(string s, int num, bool decision) {
		int p = root;
		for (int i = 0; i < s.size(); i++) {
			int idx = (s[i] == '1' ? 1 : 0);
			if (next[p][idx] == -1) {
				next[p][idx] = NewNode();
			}
			p = next[p][idx];
		}
		if (id[p] == 0) {
			id[p] = num;
			end[p] = decision;
		}
	}

	bool search(string s) {
		bool res = true;
		int p = root, cur_id = 1000000;
		if (id[p]) {
			cur_id = id[p];
			res = end[p];
		}
		for (int i = 0; i < 32; i++) {
			int idx = (s[i] == '1' ? 1 : 0);
			if (next[p][idx] == -1)
				return res;
			p = next[p][idx];
			if (id[p] && id[p] < cur_id) {
				cur_id = id[p];
				res = end[p];
			}
		}
		return res;
	}
}trie;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int i1, i2, i3, i4, count;
	char ch, deci[10];
	//Trie trie;
	trie.init();

	for (int i = 0; i < n; i++) {
		count = 32;
		scanf("%s %d.%d.%d.%d", deci, &i1, &i2, &i3, &i4);
		scanf("%c", &ch);
		if (ch == '/') scanf("%d", &count);
		ll num = (i1 << 24) + (i2 << 16) + (i3 << 8) + i4;
		bitset<32> b(num);
		string cur = b.to_string().substr(0, count);
		trie.insert(cur, i + 1, strcmp(deci, "allow") == 0);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d.%d.%d.%d", &i1, &i2, &i3, &i4);
		ll num = (i1 << 24) + (i2 << 16) + (i3 << 8) + i4;
		bitset<32> b(num);
		string cur = b.to_string();
		if (trie.search(cur)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}