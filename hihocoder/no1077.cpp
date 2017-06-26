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

const int MAX2 = 4e6 + 20;
typedef long long ll;

int tree[MAX2];
int N, Q;

void build(int left, int right, int cur) {
	if (left == right) {
		scanf("%d", &tree[cur]);
		return;
	}
	int mid = ((right + left) >> 1);
	build(left, mid, cur << 1);
	build(mid + 1, right, (cur << 1) + 1);
	tree[cur] = min(tree[cur << 1], tree[(cur << 1) + 1]);
}

void change(int k, int weight, int l, int r, int index) {
	if (l == r) {
		tree[index] = weight;
		return;
	}
	int mid = ((r + l) >> 1);
	if (k <= mid) change(k, weight, l, mid, index << 1);
	else change(k, weight, mid + 1, r, (index << 1) + 1);
	tree[index] = min(tree[index << 1], tree[(index << 1) + 1]);
}

int query(int left, int right, int cur_l, int cur_r, int index) {
	if (cur_l == left && cur_r == right) return tree[index];
	int cur_m = ((cur_r + cur_l) >> 1);
	if (right <= cur_m) return query(left, right, cur_l, cur_m, (index << 1));
	if (left >= cur_m + 1) return query(left, right, cur_m + 1, cur_r, (index << 1) + 1);
	else return min(query(left, cur_m, cur_l, cur_m, (index << 1)),
		query(cur_m + 1, right, cur_m + 1, cur_r, (index << 1) + 1));
}

int main() {
	scanf("%d", &N);
	build(1, N, 1);
	scanf("%d", &Q);
	int sig, a, b;
	for (int i = 0; i < Q; i++) {
		scanf("%d %d %d", &sig, &a, &b);
		if (sig == 0) printf("%d\n", query(a, b, 1, N, 1));
		else change(a, b, 1, N, 1);
	}
	return 0;
}