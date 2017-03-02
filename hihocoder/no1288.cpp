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

int n, p, w, h;

bool check(vector<int> vec, int size) {
	int lines = 0;
	for (int i = 0; i < vec.size(); i++) {
		int one_line = w / size;
		lines += ceil((double)vec[i] / one_line);
	}
	int one_page = h / size;

	return p >= ceil((double)lines / one_page);
}

int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cin >> n >> p >> w >> h;
		vector<int> vec(n, 0);
		for (int i = 0; i < n; i++)
			cin >> vec[i];

		int left = 1, right = min(w, h);
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (check(vec, mid)) left = mid + 1;
			else right = mid - 1;
		}
		int result = check(vec, left) ? left : left - 1;
		cout << result << endl;
	}

	return 0;
}