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

const int N = 30001;
bitset<N> high[N][5];
int ids[N];
int Rank[N][5];
int col;

bool cmp(int x, int y) {
	return Rank[x][col] < Rank[y][col];
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> Rank[i][j];
		}
	}
	for (int i = 0; i < n; i++) ids[i] = i;
	for (int j = 0; j < 5; j++) {
		col = j;
		stable_sort(ids, ids + n, cmp);
		for (int i = 1; i <= n; i++) {
			high[Rank[ids[i] + 1][j]][j] = high[Rank[ids[i] + 1][j]][j];
		}
	}
	for (int i = 0; i < n; i++) {
	
	}
	return 0;
}