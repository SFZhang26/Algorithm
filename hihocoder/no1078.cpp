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

const int MAX2 = 4e5 + 20;
typedef long long ll;

struct node {
	int val, lazy;
	node() { val = 0; lazy = -1; }
};
node tree[MAX2];
int N, Q;

void build(int left, int right, int cur) {
	if (left == right) {
		scanf("%d", &tree[cur].val);
		return;
	}
	int mid = ((right + left) >> 1);
	build(left, mid, cur << 1);
	build(mid + 1, right, (cur << 1) + 1);
	tree[cur].val = tree[cur << 1].val + tree[(cur << 1) + 1].val;
}

void do_lazy(int mid, int index, int l, int r) {
	tree[index << 1].lazy = tree[index].lazy;
	tree[index << 1].val = tree[index].lazy*(mid - l + 1);

	tree[(index << 1) + 1].lazy = tree[index].lazy;
	tree[(index << 1) + 1].val = tree[index].lazy*(r - mid);

	tree[index].lazy = -1;
}

void change(int left, int right, int weight, int l, int r, int index) {
	if (left == l&&right == r) {
		tree[index].lazy = weight;
		tree[index].val = weight*(r - l + 1);
		return;
	}
	int mid = ((r + l) >> 1);
	if (tree[index].lazy != -1) 
		do_lazy(mid, index, l, r);
	if (right <= mid) change(left, right, weight, l, mid, index << 1);
	else if (left >= mid + 1) change(left, right, weight, mid + 1, r, (index << 1) + 1);
	else {
		change(left, mid, weight, l, mid, index << 1);
		change(mid + 1, right, weight, mid + 1, r, (index << 1) + 1);
	}
	tree[index].val = tree[index << 1].val + tree[(index << 1) + 1].val;
}

int query(int left, int right, int cur_l, int cur_r, int index) {
	if (cur_l == left && cur_r == right) return tree[index].val;
	int cur_m = ((cur_r + cur_l) >> 1);
	if (tree[index].lazy != -1) 
		do_lazy(cur_m, index, cur_l, cur_r);
	if (right <= cur_m) return query(left, right, cur_l, cur_m, (index << 1));
	if (left >= cur_m + 1) return query(left, right, cur_m + 1, cur_r, (index << 1) + 1);
	else return query(left, cur_m, cur_l, cur_m, (index << 1)) + query(cur_m + 1, right, cur_m + 1, cur_r, (index << 1) + 1);
}

int main() {
	scanf("%d", &N);
	build(1, N, 1);
	scanf("%d", &Q);
	int sig, a, b, c;
	for (int i = 0; i < Q; i++) {
		scanf("%d", &sig);
		if (sig == 0) {
			scanf("%d %d", &a, &b);
			printf("%d\n", query(a, b, 1, N, 1));
		}
		else {
			scanf("%d %d %d", &a, &b, &c);
			change(a, b, c, 1, N, 1);
		}
	}
	return 0;
}