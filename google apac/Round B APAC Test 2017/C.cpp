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

ll T;

int main() {
	//open files
	ifstream f_input;
	ofstream f_output;

	f_input.open("C-small-practice.in");
	f_output.open("out_put");

	f_input >> T;

	for (int tt = 1; tt <= T; tt++) {
		ll cut = 0;
		ll N, L1, R1, A, B, C1, C2, M;
		f_input >> N >> L1 >> R1 >> A >> B >> C1 >> C2 >> M;
		vector<pair<ll, ll>> in;
		vector<ll> node;
		vector<ll> cover(2 * N + 1, 0);
		vector<ll> coverOnce(2 * N + 1, 0);
		vector<ll> count(2 * N + 1, 0);

		ll x = L1, y = R1;
		for (ll i = 0; i < N; i++) {
			//cout << "[" << L1 << " , " << R1 << "]" << endl;
			in.push_back(make_pair(L1, R1+1));
			int temp = x;
			x = (A*x + B*y + C1) % M;
			y = (A*y + B*temp + C2) % M;
			L1 = min(x, y);
			R1 = max(x, y);
		}
		for (ll i = 0; i < N; i++) {
			node.push_back(in[i].first);
			node.push_back(in[i].second);
		}
		sort(node.begin(), node.end());
		ll len = unique(node.begin(), node.end()) - node.begin();
		for (ll i = 0; i < N; i++) {
			ll l = in[i].first;
			ll r = in[i].second;
			l = lower_bound(node.begin(), node.begin() + len, l) - node.begin() + 1;
			r = lower_bound(node.begin(), node.begin() + len, r) - node.begin() + 1;
			count[l]++;
			count[r]--;
		}

		for (ll i = 1; i <= len; i++) {
			count[i] += count[i - 1];

			cover[i] = cover[i - 1];
			if (count[i] > 0) cover[i] += (node[i] - node[i - 1]);

			coverOnce[i] = coverOnce[i - 1];
			if (count[i] == 1) coverOnce[i] += (node[i] - node[i - 1]);
		}
		for (ll i = 0; i <N; i++) {
			ll l = in[i].first;
			ll r = in[i].second;
			l = lower_bound(node.begin(), node.begin() + len, l) - node.begin();
			r = lower_bound(node.begin(), node.begin() + len, r) - node.begin();
			cut = max(cut, coverOnce[r] - coverOnce[l]);
		}
		ll result = cover[len] - cut;
		f_output << "Case #" << tt << ": " << result << endl;
		cout << tt << " finished" << endl;
	}

	f_input.close();
	f_output.close();

}