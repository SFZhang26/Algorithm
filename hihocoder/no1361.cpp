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
	string str;
	cin >> str;
	vector<bool> count(26, true);
	int size = str.size();

	int already = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'J') str[i] = 'I';
		if (count[str[i] - 'A']) {
			cout << str[i];
			count[str[i] - 'A'] = false;
			already++;
			if (already % 5 == 0) cout << endl;
		}
	}
	for (char i = 'A'; i <= 'Z'; i++) {
		if (i == 'J') continue;
		if (count[i - 'A']) {
			cout << i;
			already++;
			if (already % 5 == 0) cout << endl;
		}
		if (already == 25) break;
	}
	return 0;
}