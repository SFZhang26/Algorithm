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

int main() {
	int n, m;
	cin >> n;
	map<string, string> father;
	for (int i = 0; i < n; i++) {
		string f, s;
		cin >> f >> s;
		father[s] = f;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		string name1, name2;
		cin >> name1 >> name2;
		map<string, bool> ancestor;
		ancestor[name1] = true;
		while (father.find(name1) != father.end()) {
			name1 = father[name1];
			ancestor[name1] = true;
		}
		bool flag = false;
		if (ancestor.find(name2) != ancestor.end()) {
			cout << name2 << endl;
			flag = true;
		}
		else {
			while (father.find(name2) != father.end()) {
				name2 = father[name2];
				if (ancestor.find(name2) != ancestor.end()) {
					cout << name2 << endl;
					flag = true;
					break;
				}
			}
		}
		if (!flag) cout << -1 << endl;
	}

	return 0;
}