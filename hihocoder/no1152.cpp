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

set<int> fibo = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

void solve(set<string> &s, string str) {
	set<char> contain;
	for (int i = 0; i < str.size(); i++) {
		contain.clear();
		for (int j = i; j < str.size(); j++) {
			contain.insert(str[j]);
			if (fibo.find(contain.size()) != fibo.end()) {
				s.insert(str.substr(i, j - i + 1));
			}
		}
	}
}

int main() {
	string str;
	cin >> str;
	set<string> s;
	solve(s, str);
	for (set<string>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}