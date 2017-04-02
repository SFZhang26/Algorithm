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
	map<int, int> wall;
	int m, cur;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> cur;
			sum += cur;
			if (j < m - 1) wall[sum]++;
		}
	}
	int big = 0;
	for (map<int, int>::iterator it = wall.begin(); it != wall.end(); it++) {
		big = max(big, it->second);
	}
	cout << n - big << endl;
	return 0;
}