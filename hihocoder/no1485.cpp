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

int SIZE = 100001;

int main() {
	vector<int> pat = { 2, 1, 1 };
	map<char, int>m;
	m['h'] = 0;
	m['i'] = 1;
	m['o'] = 2;
	vector<int> cur = { 0, 0, 0 };
	string str;
	cin >> str;
	int result = SIZE;
	int i = 0;
	queue<int> pos;
	while (str[i] != 'h'&&str[i] != 'i'&&str[i] != 'o') i++;
	int start = i;
	while (i < str.size()) {
		char ch = str[i];
		if (ch == 'h' || ch == 'i' || ch == 'o') {
			cur[m[ch]]++;
			pos.push(i);
			if (cur == pat) 
				result = min(result, i - start + 1);
			else if (cur[m[ch]]>pat[m[ch]]) {
				while (!pos.empty()) {
					start = pos.front();
					pos.pop();
					cur[m[str[start]]]--;
					int next_start = pos.front();
					if (cur == pat) result = min(result, i - next_start + 1);
					if (str[start] == ch) {
						start = next_start;
						break;
					}
				}
			}
		}
		i++;
	}
	if (result == SIZE) cout << -1 << endl;
	else cout << result << endl;
	return 0;
}