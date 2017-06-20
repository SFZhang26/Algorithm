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
int N, M, S, T;

struct node{
	int v, len;
	node(int vertex, int L) { v = vertex; len = L; }
};

queue<int> que;
vector<node> edge[MAX];
bool visited[MAX];
int dist[MAX];

int main() {
	cin >> N >> M >> S >> T;
	for (int i = 0; i <= N; i++) {
		dist[i] = 1e9;
		visited[i] = false;
	}
	dist[S] = 0;
	que.push(S);
	for (int i = 0; i < M; i++) {
		int u, v, len;
		cin >> u >> v >> len;
		edge[u].push_back(node(v, len));
		edge[v].push_back(node(u, len));
	}
	while (que.size()>0) {
		int cur = que.front();
		que.pop();
		visited[cur] = false;
		for (int i = 0; i < edge[cur].size(); i++) {
			int v = edge[cur][i].v;
			if (dist[v]>dist[cur] + edge[cur][i].len) {
				dist[v] = dist[cur] + edge[cur][i].len;
				if (!visited[v]) {
					que.push(v);
					visited[v] = true;
				}
			}
		}
	}
	cout << dist[T] << endl;
	return 0;
}