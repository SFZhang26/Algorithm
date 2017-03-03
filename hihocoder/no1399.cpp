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

//greedy 下一个加入原队列，能消掉即消掉

int solve(ll n) {
	int result = 0;
	if (n == 0) return 0;

	int flag = -1;
	for (int i = 0; i < n; i++) {
		int next;
		cin >> next;
		int temp = next % 2;
		if (flag == -1) {
			flag = temp;
			result++;
		}
		else {
			if (flag + temp == 1) {
				result--;
			}
			else result++;
			
			if (result == 0) flag = -1;
		}
	}
	return result;
}


int main() {
	ll n;
	cin >> n;
	cout << solve(n) << endl;

	return 0;
}