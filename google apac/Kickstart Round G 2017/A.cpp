#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

typedef long long ll;

int T;
ll a, n, p;

ll solve(ll a, ll b, ll p) {
	if (a == 0) return 0;
	if (b == 1) return (a%p);
	ll half = solve(a, b / 2, p);
	if ((b & 1) == 0) return (half*half) % p;
	else return (half*half*a) % p;
}

int main() {
	//open files
	ifstream f_input;
	ofstream f_output;

	f_input.open("A-large-practice.in");
	f_output.open("out_put");

	f_input >> T;
	for (int tt = 1; tt <= T; tt++) {
		f_input >> a >> n >> p;
		ll res = (a%p);
		for (int i = 2; i <= n; i++) {
			res = solve(res, i, p);
		}
		f_output << "Case #" << tt << ": " << res << endl;
		//cout << tt << endl;
	}

	f_input.close();
	f_output.close();

	return 0;
}