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
	int n, result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		result ^= cur;
	}
	if (result) cout << "Alice" << endl;
	else cout << "Bob" << endl;

	return 0;
}