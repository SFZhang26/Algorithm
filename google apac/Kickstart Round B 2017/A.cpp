#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

typedef long long ll;

int T;
int MOD = 1000000007;

int main() {
	//open files
	ifstream f_input;
	ofstream f_output;

	f_input.open("A-large-practice.in");
	f_output.open("out_put");

	f_input >> T;

	for (int tt = 1; tt <= T; tt++) {
		int n;
		ll result = 0;
		f_input >> n;
		vector<ll> nums(n, 0);
		for (int i = 0; i < n; i++) {
			f_input >> nums[i];
		}
		for (int i = 0; i < n - 1; i++) {
			ll p = 1;
			for (int j = i + 1; j < n; j++) {
				result = (result + (nums[j] - nums[i])*p) % MOD;
				p = (p * 2) % MOD;
			}
		}

		f_output << "Case #" << tt << ": " << result << endl;
		cout << tt << " finished" << endl;
	}

	f_input.close();
	f_output.close();
}