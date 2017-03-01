#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>

using namespace std;

typedef long long ll;

int T;

//返回base进制、长度为len全为1的串所表示的值re
ll cal(ll base, ll len, ll n) {
	ll re = 0;
	for (int i = 0; i < len; i++) {
		re = re*base + 1;
		if (re>n) return -1;
	}
	return re;
}

ll solve(ll n) {
	int result = 0;
	//转化后长度len
	for (int len = 60; len >=3; len--) {
		ll left = 2;
		ll right = pow(n, 1 / double(len - 1));

		while (left <= right) {
			ll mid = left + (right - left) / 2;
			ll cur = cal(mid, len, n);
			if (cur == n) return mid;
			else if (cur == -1) right = mid - 1;
			else left = mid + 1;
		}
	}
	if (result == 0) return n - 1;
}

int main() {
	//open files
	ifstream f_input;
	ofstream f_output;

	f_input.open("B-large-practice.in");
	f_output.open("out_put");

	f_input >> T;

	for (int k = 1; k <= T; k++) {
		ll n;
		f_input >> n;
		ll result = solve(n);
		f_output << "Case #" << k << ": " << result << endl;
		cout << k << endl;
	}

	f_input.close();
	f_output.close();
}