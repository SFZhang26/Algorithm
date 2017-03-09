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

int solve(vector<int> nums,int target){
	sort(nums.begin(), nums.end());
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) return mid + 1;
		else if (nums[mid] > target) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> vec(n, 0);
	for (int i = 0; i < n; i++) cin >> vec[i];
	int reuslt = solve(vec, k);
	cout << reuslt << endl;

	return 0;
}