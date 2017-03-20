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
		string cur;
		cin >> cur;
		bool flag = false;
		for (int i = 0; i < cur.size(); i++) {
			if (cur[i] == 'A') {
				if (flag) {
					cout << "NO" << endl;
					break;
				}
				else flag = true;
			}
			else if (cur[i] == 'L') {
				if (i + 1 < cur.size() && i + 2 < cur.size() && cur[i + 1] == 'L'&&cur[i + 2] == 'L') {
					cout << "NO" << endl;
					break;
				}
			}
			if (i == cur.size() - 1)cout << "YES" << endl;
		}
	}
	return 0; 
}