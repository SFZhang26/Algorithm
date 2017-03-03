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



int main() {
	int n;
	cin >> n;
	vector<vector<int>> grid(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> grid[i][j];
			if (i == 0) continue;
			if (j == 0) grid[i][j] += grid[i - 1][j];
			else grid[i][j] = max(grid[i - 1][j - 1] + grid[i][j], grid[i - 1][j] + grid[i][j]);
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) result = max(result, grid[n - 1][i]);
	cout << result << endl;

	return 0;
}