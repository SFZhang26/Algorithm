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

int queryTree[1000001][20] = { 0 };
int n;
void construct() {
	int len = int(log((double)n) / log(2.0));
	for (int i = 1; i <= len; i++) {
		for (int j = 0; j + (1 << (i - 1)) < n; j++) {
			queryTree[j][i] = min(queryTree[j][i - 1], queryTree[j + (1 << (i - 1))][i - 1]);
		}
	}
}

void query(int l, int r) {
	int row = int(log((double)(r - l + 1)) / log(2.0));
	int res = min(queryTree[l][row], queryTree[r - (1 << row) + 1][row]);
	printf("%d\n", res);
}

int main() {
	int q;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &queryTree[i][0]);
	}
	construct();
	scanf("%d", &q);
	int l, r;
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &l, &r);
		query(l - 1, r - 1);
	}
	return 0;
}