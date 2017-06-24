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

int T;
const int MAX = 1e5 + 1;
int N, M, a, b;
int degree[MAX];
vector<int> pre[MAX];

int main() {
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			degree[i] = 0;
			pre[i] = vector<int>();
		}
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			degree[b]++;
			pre[a].push_back(b);
		}
		queue<int> que;
		for (int i = 1; i <= N; i++) {
			if (degree[i] == 0) {
				que.push(i);
			}
		}
		int count = 0;
		while (!que.empty()) {
			int cur = que.front();
			que.pop();
			count++;
			for (int i = 0; i < pre[cur].size(); i++) {
				degree[pre[cur][i]]--;
				if (degree[pre[cur][i]] == 0) {
					que.push(pre[cur][i]);
				}
			}
		}
		cout << (count == N ? "Correct" : "Wrong") << endl;
	}
	return 0;
}