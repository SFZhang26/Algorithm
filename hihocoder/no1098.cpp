#include <cstdio>
#include <cstring>
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

const int MAX = 100001;
int N, M;

struct node{
	int v, len;
	node(int vertex, int L) { v = vertex; len = L; }
};

int m[MAX];

int find_represent(int u) {
	if (u == m[u]) return u;
	else {
		m[u] = find_represent(m[u]);
		return m[u];
	}
}

void link(int u, int v) {
	if (m[u] == -1) m[u] = u;
	else {
		u = find_represent(u);
	}
	if (m[v] == -1) m[v] = v;
	else {
		v = find_represent(v);
	}
	m[v] = u;
}

bool check(int u, int v) {
	if (m[u] == -1 || m[v] == -1) return false;
	u = find_represent(u);
	v = find_represent(v);
	return u == v;
}

int uu, vv, len;

struct cmp {
	bool operator()(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2) {
		return p1.second > p2.second;
	}
};

priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> que;
map<pair<int, int>, int> edge;

int main() {
	for (int i = 0; i < MAX; i++) m[i] = -1;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> uu >> vv >> len;
		int a = min(uu, vv);
		int b = max(uu, vv);
		if (edge.find(make_pair(a, b)) == edge.end())
			edge[make_pair(a, b)] = len;
		else
			edge[make_pair(a, b)] = min(edge[make_pair(a, b)], len);
	}
	for (map<pair<int, int>, int>::iterator it = edge.begin(); it != edge.end(); it++) {
		que.push(make_pair(it->first, it->second));
	}
	int count = 0;
	int res = 0;
	while (count < N-1) {
		pair<pair<int, int>, int> p = que.top();
		que.pop();
		if (!check(p.first.first, p.first.second)) {
			link(p.first.first, p.first.second);
			res += p.second;
			count++;
		}
	}
	cout << res << endl;
	return 0;
}