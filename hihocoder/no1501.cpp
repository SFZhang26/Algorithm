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

int main() {
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		string s;
		cin >> s;
		string res = "";
		bool bigger = false;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '_') {
				bigger = true;
			}
			else if (s[i] >= 'A' && s[i] <= 'Z') {
				res = res + "_" + char(s[i] - 'A' + 'a');
			}
			else if (bigger) {
				res = res + char(s[i] - 'a' + 'A');
				bigger = false;
			}
			else {
				res += s[i];
			}
		}
		cout << res << endl;
	}
	return 0;
}