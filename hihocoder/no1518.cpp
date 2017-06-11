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

int main() {
	int n;
	cin >> n;
	vector<int> nums(n, 0), res(n,0);
	int result = 0;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		nums[i]--;
	}
	for (int i = 0; i < n; i++) {
		if (res[i]>0) {
			result = max(result, res[i]);
			continue;
		}
		int start = i;
		int count = 0;
		while (nums[i] != start && nums[i] != i && res[i] == 0) {
			count += 1;
			i = nums[i];
		}
		int base = res[i];
		i = start;
		while (nums[i] != start && nums[i] != i && res[i] == 0) {
			if (res[i] > 0) continue;
			res[i] += (base + count);
			count--;
			i = nums[i];
		}
		i = start;
		result = max(result, res[i]);
	}
	cout <<  max(result, 1) << endl;
	return 0;
}