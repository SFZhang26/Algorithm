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
	vector<int> vec(n, 0);
	int cur = n;
	int res = 0;
	for (int i = 0; i < n; i++) cin >> vec[i];
	for (int i = n - 1; i >= 0; i--) {
		if (vec[i] == cur) {
			cur--;
			res++;
		}
	}
	
	cout << n - res << endl;
	return 0;
}