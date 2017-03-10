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

int helper(vector<int> nums, int left, int right,int target) {
	if (left >= right) return 1;
	int i = left, j = right;
	int pivot = nums[left];
	while (i < j) {
		while (i < j&&nums[j] > pivot) j--;
		nums[i] = nums[j];
		while (i < j&&nums[i] < pivot) i++;
		nums[j] = nums[i];
	}
	nums[i] = pivot;
	if (target == pivot) return i - left + 1;
	else if (target>pivot) return i - left + 1 + helper(nums, i + 1, right, target);
	else return helper(nums, left, i - 1, target);
}

int solve(int n, int k) {
	vector<int> vec(n, 0);
	bool flag = false;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		if (vec[i] == k) flag = true;
	}
	if (!flag) return -1;
	else return helper(vec, 0, n - 1, k);
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << solve(n, k) << endl;
	return 0;
}