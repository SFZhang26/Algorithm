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
errno_t err;
FILE *f_input, *f_output;

vector<ll> count(string s) {
	vector<ll> vec(26, 0);
	for (int i = 0; i < s.size(); i++)
		vec[s[i] - 'a']++;
	return vec;
}


ll solve(map<vector<ll>, ll> m, string sentence, int max_length) {
	vector<ll> dp(sentence.size() + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < sentence.size(); i++) {
		vector<ll> num(26, 0);
		for (int j = 0; j < max_length; j++) {
			if (i - j < 0) continue;

			num[sentence[i - j] - 'a']++;
			if (((i - j) != 0 && dp[i - j] == 0) || m.find(num) == m.end()) continue;
			else dp[i + 1] += (dp[i - j] * m[num]);
		}
		//cout << dp[i + 1] << endl;
	}
	return dp.back() % 1000000007;
}

int main() {
	//open files
	ifstream f_input;
	ofstream f_output;

	f_input.open("C-large-practice.in");
	f_output.open("out_put");

	//read
	f_input >> T;

	for (int k = 1; k <= T; k++) {
		int V;
		int S;
		f_input >> V >> S;
		
		map<vector<ll>, ll> m;

		int max_length = 0;
		for (int i = 0; i < V; i++) {
			string temp="";
			f_input >> temp;
			//cout << temp << endl;
			max_length = fmax(max_length, temp.size());
			vector<ll> cur = count(temp);
			if (m.find(cur) == m.end()) m[cur] = 1;
			else m[cur]++;
		}
		
		f_output << "Case #" << k << ":";
		for (int i = 0; i < S; i++) {
			string sentence;
			f_input >> sentence;
			ll result = solve(m, sentence, max_length);
			f_output << " " << result;
			cout << result << endl;
		}
		f_output << "\n";
	}

	f_input.close();
	f_output.close();
}