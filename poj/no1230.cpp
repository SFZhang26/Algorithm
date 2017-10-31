#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXLEN = 101;
int T, n, k;
int l1, l2, r1, r2;

int main() {
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		cin >> n >> k;
		vector<vector<int>> grid(MAXLEN, vector<int>(MAXLEN, 0));
		for (int i = 0; i < n; i++) {
			cin >> l1 >> r1 >> l2 >> r2;
			int left = min(l1, l2);
			int right = max(l1, l2);
			for (int j = left; j <= right; j++) grid[r1][j] = i + 1;
		}
		int res = 0;
		for (int j = 0; j < MAXLEN; j++) {
			int count = 0;
			for (int i = 0; i < MAXLEN; i++) count += (grid[i][j]>0 ? 1 : 0);
			while (count>k) {
				int index = -1, longest = -1;
				for (int i = 0; i < MAXLEN; i++) {
					if (grid[i][j] == 0) continue;
					int jj = j, len = 0;
					while (jj < MAXLEN && grid[i][jj] == grid[i][j]) {
						len++;
						jj++;
					}
					if (len > longest) {
						index = i;
						longest = len;
					}
				}
				for (int jj = j; jj < j + longest; jj++) 
					grid[index][jj] = 0;
				res++;
				count--;
			}
		}
		cout << res << endl;
	}

	return 0;
}