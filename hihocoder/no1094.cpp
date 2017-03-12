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

int n, m;

string roll(vector<string> grid, int i, int j) {
	string re = "";
	re += grid[i - 1][j - 1];
	re += grid[i - 1][j];
	re += grid[i - 1][j + 1];
	re += grid[i][j + 1];
	re += grid[i + 1][j + 1];
	re += grid[i + 1][j];
	re += grid[i + 1][j - 1];
	re += grid[i][j - 1];
	return re;
}

bool check(string s1, string s2) {
	int start = 0;
	while (start < 8) {
		int i = 0;
		for (; i < 8; i++) {
			if (s1[(start + i) % 8] != s2[i]) break;
		}
		if (i == 8) return true;
		start += 2;
	}
	return false;
}

vector<int> solve(vector<string> grid, vector<string> pattern) {
	vector<int> result;
	string pat = roll(pattern, 1, 1);
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (grid[i][j] != pattern[1][1]) continue;
			if (check(roll(grid, i, j), pat)) {
				result.push_back(i + 1);
				result.push_back(j + 1);
			}
		}
	}
	return result;
}

int main() {
	cin >> n >> m;
	vector<string> grid(n, "");
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}
	vector<string> pattern(3, "");
	for (int i = 0; i < 3; i++) {
		cin >> pattern[i];
	}
	vector<int> result = solve(grid, pattern);
	for (int i = 0; i < result.size()/2; i++) {
		cout << result[2 * i] << " " << result[2 * i + 1] << endl;
	}
	return 0;
}