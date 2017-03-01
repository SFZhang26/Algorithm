#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <bitset>

using namespace std;

typedef long long ll;

int T;
const ll MOD = 1000000007;

ll A, B, N, K;

ll myPow(ll i, ll a) {
	if (a == 0) return 1%K;//important
	if (a == 1) return i%K;
	ll half = myPow(i, a / 2);
	if (a & 1) return half*half % K*i % K;
	return half*half % K;
}

int main() {
	//open files
	ifstream f_input;
	ofstream f_output;

	f_input.open("B-large-practice.in");
	f_output.open("out_put");

	f_input >> T;

	for (int tt = 1; tt <= T; tt++) {
		ll result = 0;
		f_input >> A >> B >> N >> K;

		vector<ll> li(K + 1, 0);
		vector<ll> lj(K + 1, 0);
		vector<ll> add(K + 1, 0);

		ll div = N % K;
		ll num = N / K;
		ll cut = 0;

		for (int i = 0; i < K; i++) {
			add[i] = num + (i <= div);
		}
		add[0]--;

		for (ll i = 0; i < K; i++) {
			ll ri = myPow(i, A);
			ll rj = myPow(i, B);
			li[ri] = (li[ri] + add[i]) % MOD;
			lj[rj] = (lj[rj] + add[i]) % MOD;
			if ((ri + rj) % K == 0) {
				cut = (cut + add[i]) % MOD;
			}
		}

		for (ll i = 0; i < K; i++) {
			ll j = (K - i) % K;
			result = (result + (li[i] * lj[j]) % MOD) % MOD;
		}
		result = (result - cut + MOD) % MOD;
		f_output << "Case #" << tt << ": " << result << endl;
		cout << tt << " finished" << endl;
	}

	f_input.close();
	f_output.close();
}