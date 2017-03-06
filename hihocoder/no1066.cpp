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

const ll MOD = 1e9 + 7;

int T;

int n;
map<string, string> m;

string find_represent(string name) {
	if (name == m[name]) return name;
	else {
		m[name] = find_represent(m[name]);
		return m[name];
	}
}

void link(string n1, string n2) {
	if (m.find(n1) == m.end()) m[n1] = n1;
	else {
		n1 = find_represent(n1);
	}
	if (m.find(n2) == m.end()) m[n2] = n2;
	else {
		n2 = find_represent(n2);
	}
	m[n2] = n1;
}

bool check(string n1, string n2) {
	if (m.find(n1) == m.end() || m.find(n2) == m.end()) return false;
	n1 = find_represent(n1);
	n2 = find_represent(n2);
	return n1 == n2;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int op;
		string name1, name2;
		cin >> op >> name1 >> name2;
		if (op == 0) link(name1, name2);
		else {
			bool result = check(name1, name2);
			if (result) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}

	return 0;
}