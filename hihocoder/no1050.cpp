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

int last = 1;

struct Node {
	int val;
	vector<int> next;
	Node() :val(0) {};
};

int build_node(vector<Node> &node, vector<bool> &visited, int root) {
	visited[root] = true;
	bool flag = false;
	vector<int> neigh = node[root].next;

	int result = 0;
	int first = 0;
	int second = 0;
	for (int i = 0; i < neigh.size(); i++) {
		if (!visited[neigh[i]]) {
			flag = true;
			int cur = build_node(node, visited, neigh[i]);
			if (cur>first) {
				second = first;
				first = cur;
			}
			else if (cur > second) second = cur;
		}
	}
	if (!flag) return 1;
	last = max(last, first + second);
	return first + 1;
}

void solve(int n){
	if (n == 1) return;
	vector<Node> node(n + 1, Node());
	vector<bool> visited(n + 1, false);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		node[u].next.push_back(v);
		node[v].next.push_back(u);
	}
	build_node(node, visited, 1);
}

int main() {
	int n;
	cin >> n;
	solve(n);
	cout << last << endl;

	return 0;
}