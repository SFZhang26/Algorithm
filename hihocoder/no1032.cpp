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


int solve(string str) {
	if (str.size() == 0) return 0;

	int result = 0;
	string s = "$#";
	for (int i = 0; i < str.size(); i++) {
		s += str[i];
		s += "#";
	}
	vector<int> f(s.size(), 1);
	int id = 0;
	int cur;
	for (int i = 1; i < f.size(); i++) {
		int strech = id + f[id];
		if (strech>i)
			cur = min(f[2 * id - i], strech - i);
		else
			cur = 1;
		while (i - cur >= 0 && i + cur < s.size() && s[i - cur] == s[i + cur]) cur++;

		if (i + cur>strech) id = i;

		result = max(result, cur);
		f[i] = cur;
	}
	return result - 1;
}

int main() {
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		string str;
		cin >> str;
		cout << solve(str) << endl;

	}

	return 0;
}