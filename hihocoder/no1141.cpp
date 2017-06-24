#include <cstdio>
#include <cstring>
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

const int MAX = 1e5 + 1;
int N;
ll nums[MAX], temp[MAX];

ll sort_and_count(int left, int right) {
	if (left >= right) return 0;
	int mid = left + (right - left) / 2;
	ll l = sort_and_count(left, mid);
	ll r = sort_and_count(mid + 1, right);
	ll add = 0;
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right) {
		if (nums[i] > nums[j]) {
			add += (mid - i + 1);
			temp[k++] = nums[j++];
		}
		else {
			temp[k++] = nums[i++];
		}
	}
	if (i <= mid)	for (int t = right; t >= k; t--) nums[t] = nums[mid - (right - t)];
	for (int t = left; t < k; t++) nums[t] = temp[t];
	return l + r + add;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	cout << sort_and_count(0, N-1) << endl;
	return 0;
}