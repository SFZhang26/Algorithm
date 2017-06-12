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

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.first < p2.first;
}
int main() {
	string s;
	cin >> s;
	vector<pair<int, int>> res;
	stack<int> stk;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') 
			stk.push(i + 1);
		else {
			res.push_back(make_pair(stk.top(), i + 1));
			stk.pop();
		}
	}
	sort(res.begin(), res.end(), cmp);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].first << " " << res[i].second << endl;
	}
	return 0;
}