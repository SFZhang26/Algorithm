#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <fstream>

using namespace std;

typedef long long ll;

int T;

int main() {
	ifstream f_input;
	ofstream f_output;

	f_input.open("D-large-practice.in");
	f_output.open("out_put");

	f_input >> T;

	for (int tt = 1; tt <= T; tt++) {
		int N;
		bool result = false;
		f_input >> N;
		vector<int> vec_a;
		vector<int> vec_d;
		for (int i = 0; i < N; i++) {
			int a, d;
			f_input >> a >> d;
			vec_a.push_back(a);
			vec_d.push_back(d);
		}
		//state记录是否需要跳过
		vector<bool> state(N, true);
		bool flag = true;
		for (int i = 0; i < N; i++) {
			//当前最大的a和d
			int curMax_a = 0;
			int curMax_d = 0;
			for (int j = 0; j < N; j++) {
				if (state[j]) {
					flag = false;
					curMax_a = max(curMax_a, vec_a[j]);
					curMax_d = max(curMax_d, vec_d[j]);
				}
			}
			if (flag) break;
			for (int j = 0; j < N; j++) {
				if (state[j]) {
					if (vec_a[j] == curMax_a&&vec_d[j] == curMax_d) {
						result = true;
						break;
					}
					else if (vec_a[j] == curMax_a || vec_d[j] == curMax_d) {
						state[j] = false;
					}
				}
			}
		}
		if (result) f_output <<"Case #"<<tt<<": YES"<<endl;
		else  f_output << "Case #" << tt << ": NO" << endl;
		
		cout << tt << " finished" << endl;
	}

	f_input.close();
	f_output.close();
}