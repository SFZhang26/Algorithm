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


int solve(vector<int> nums, int left, int right, int kth) {
	int l = left, r = right;
	int pivot = nums[left];
	while (l < r) {
		while (l < r && nums[r] > pivot) r--;
		if(l<r) nums[l++] = nums[r];
		while (l < r && nums[l] < pivot) l++;
		if(l<r) nums[r--] = nums[l];
	}
	nums[l] = pivot;
	if ((l - left) == kth) return pivot;
	else if (l - left>kth) return solve(nums, left, l-1, kth);
	else return solve(nums, l+1, right, kth - (l - left) - 1);
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++) cin >> nums[i];
	cout << solve(nums, 0, n - 1, k - 1) << endl;
	return 0; 
}