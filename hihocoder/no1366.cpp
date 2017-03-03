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
	int N;
	cin >> N;
	map<string, bool> m;
	int result = 0;
	for (int i = 0; i < N; i++) {
		string cur;
		cin >> cur;
		m[cur] = true;
		reverse(cur.begin(), cur.end());
		if (m.find(cur) != m.end()) result++;
	}
	cout << result << endl;
}