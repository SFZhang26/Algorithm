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

int main() {
	ifstream f_input;
	ofstream f_output;

	f_input.open("A-large-practice.in");
	f_output.open("out_put");

	f_input >> T;
	for (int tt = 1; tt <= T; tt++) {
		ll l, r;
		f_input >> l >> r;
		ll n = min(l, r);
		cout << n << endl;
		f_output << "Case #" << tt << ": " << n*(n + 1) / 2 << endl;
		cout << tt << "finished" << endl;
	}
	f_input.close();
	f_output.close();
}