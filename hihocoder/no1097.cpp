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

int n;

int main() {
	cin >> n;
	vector<vector<int>> grid(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	vector<int> dist(grid[0]);
	vector<bool> used(n, false);
	used[0] = true;
	int result = 0;
	for (int i = 1; i < n; i++) {
		int cur = 1000000000;
		int index = -1;
		for (int j = 0; j < n; j++) {
			if ((!used[j]) && dist[j] <= cur) {
				cur = dist[j];
				index = j;
			}
		}
		result += cur;
		used[index] = true;
		for (int j = 0; j < n; j++) {
			if (!used[j]) {
				dist[j] = min(dist[j], grid[index][j]);
			}
		}
	}
	cout << result << endl;
	return 0;
}