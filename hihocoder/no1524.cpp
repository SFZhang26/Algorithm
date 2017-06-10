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

int temp[100000] = { 0 };

int sort_and_count(vector<int> &vec, int left, int right) {
	if (left >= right) {
		return 0;
	}
	int mid = left + (right - left) / 2;
	int res_l = sort_and_count(vec, left, mid);
	int res_r = sort_and_count(vec, mid + 1, right);
	int res_join = 0;
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right) {
		if (vec[i] <= vec[j]) {
			temp[k++] = vec[i++];
		}
		else {
			res_join += (mid + 1 - i);
			temp[k++] = vec[j++];
		}
	}
	while (i <= mid) temp[k++] = vec[i++];
	while (j <= right) temp[k++] = vec[j++];
	for (int a = left; a <= right; a++) vec[a] = temp[a];
	return res_l + res_r + res_join;
}

int main() {
	int n;
	cin >> n;
	vector<int> vec(n, 0);
	for (int i = 0; i < n; i++) cin >> vec[i];
	int res = sort_and_count(vec, 0, n - 1);
	cout << res << endl;
	return 0;
}