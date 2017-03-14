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
int n;
int result;
int price[50] = { 0 };
int value[50] = { 0 };

void solve(int start, int cur_value, int cur_price, int num) {
	if ((cur_price % 10) == 0) result = max(result, cur_value);
	if (num == 3) {
		return;
	}
	for (int i = start; i < n; i++) {
		solve(i + 1, cur_value + value[i], cur_price + price[i], num + 1);
	}
}

int main() {
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			double a;
			cin >> a >> value[i];
			price[i] = a * 2;
			//cout << price[i] << endl;
		}
		result = 0;
		solve(0, 0, 0, 0);
		cout << result << endl;
	}
	return 0;
}