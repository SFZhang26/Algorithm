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

void recur(vector<string> &vec, int cur, int n, int all, int start) {
	if (n == 0) {
		if (all == 5 && cur > 23) return;
		if (all == 6 && cur > 59) return;
		string time = to_string(cur);
		if (time.size() == 1) time = "0" + time;
		vec.push_back(time);
		return;
	}
	for (int i = start; i <= all - n + 1; i++) {
		recur(vec, cur + pow(2, i), n - 1, all, i + 1);
	}
}

vector<string> get(int n, int all) {
	vector<string> vec;
	recur(vec, 0, n, all, 0);
	return vec;
}

int main() {
	int n;
	cin >> n;
	vector<string> result;
	for (int i = max(0,n-6); i <= min(5, n); i++) {
		int j = n - i;
		vector<string> h = get(i, 5);
		vector<string> m = get(j, 6);
		for (int j = 0; j < h.size(); j++) {
			for (int k = 0; k < m.size(); k++) {
				result.push_back(h[j] + ":" + m[k]);
			}
		}
	}

	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

	return 0;
}