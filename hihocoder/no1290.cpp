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

const int LARGE = 100000;

int T;
int n, m;
int main() {
	cin >> n >> m;
	vector<vector<char>> grid(n + 1, vector<char>(m + 1, 'b'));
	vector<vector<int>> dp1(n, vector<int>(m, LARGE));
	vector<vector<int>> dp2(n, vector<int>(m, LARGE));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	if (grid[0][0] == '.') {
		dp1[0][0] = 0;
		dp2[0][0] = 0;
	}
	else {
		dp1[0][0] = 1;
		dp2[0][0] = 1;
	}
	for (int j = 1; j < m; j++) {
		if (grid[0][j] == 'b') dp1[0][j] = dp1[0][j-1] + 1;
		else dp1[0][j] = dp1[0][j-1];
	}
	if (n>1) {
		if (m > 1) {
			if (grid[0][1] == '.') dp2[1][0] = dp2[0][0] + 1;
			else dp2[1][0] = dp2[0][0];
		}
		else dp2[1][0] = dp2[0][0];
		if (grid[1][0] == 'b') dp2[1][0]++;
	}
	for (int i = 2; i < n; i++) {
		if (grid[i][0] == 'b') dp2[i][0] = dp2[i - 1][0] + 1;
		else dp2[i][0] = dp2[i - 1][0];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			int fromLeft1 = dp1[i][j - 1];
			int fromLeft2 = dp2[i][j - 1];
			if (grid[i + 1][j - 1] == '.') fromLeft2++;
			dp1[i][j] = min(fromLeft1, fromLeft2);

			int fromTop1 = dp1[i - 1][j];
			int fromTop2 = dp2[i - 1][j];
			if (grid[i - 1][j + 1] == '.') fromTop1++;

			dp2[i][j] = min(fromTop1, fromTop2);

			if (grid[i][j] == 'b') {
				dp1[i][j]++;
				dp2[i][j]++;
			}
		}
	}
	/*cout << "-----------------------------" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dp1[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----------------------------" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dp2[i][j] << " ";
		}
		cout << endl;
	}*/

	cout << min(dp1[n - 1][m - 1], dp2[n - 1][m - 1]) << endl;

	return 0;
}