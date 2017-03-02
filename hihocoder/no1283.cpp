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

int main() {
	
	int n;
	cin >> n;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int end = nums.size() - 2;
	while (end >= 0&&nums[end]<nums[end+1]) {
		end--;
	}
	if (end < 0) cout << nums[0] << endl;
	else {
		for (int i = 0; i <= end; i++) cout << nums[i] << " ";
		cout << endl;
	}

	return 0;
}