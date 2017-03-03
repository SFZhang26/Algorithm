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

int solve(int n, int m, vector<int> vec) {
	if (m >= n) return 100;
	vector<int> day;
	day.push_back(vec[0] - 1);
	for (int i = 1; i < vec.size(); i++) day.push_back(vec[i] - vec[i - 1] - 1);
	day.push_back(100 - vec.back());

	int result = 0;
	int cur = 0;
	for (int i = 0; i < day.size(); i++) {
		cur += day[i];
		if (i >= m + 1) cur -= day[i - m - 1];
		result = max(result, cur);
	}
	return result + m;
}

int main() {
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		int n, m;
		cin >> n >> m;
		vector<int> vec;
		for (int i = 0; i < n; i++) {
			int day;
			cin >> day;
			vec.push_back(day);
		}
		cout << solve(n, m, vec) << endl;
	}
	return 0;
}