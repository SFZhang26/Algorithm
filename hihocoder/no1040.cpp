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

bool parallel(vector<int> l1, vector<int> l2) {
	if ((l1[0] * l2[1]) != (l1[1] * l2[0])) return false;
	if ((l1[0] * l2[2]) == (l1[2] * l2[0]) && (l1[1] * l2[2]) == (l1[2] * l2[1])) return false;
	return true;
}

bool vertical(vector<int> l1, vector<int> l2) {
	return (l1[0] * l2[0] + l1[1] * l2[1]) == 0;
}

bool judge(vector<vector<int>> line) {
	if (parallel(line[0], line[1]) && parallel(line[2], line[3]) && vertical(line[0], line[2])) return true;
	if (parallel(line[0], line[2]) && parallel(line[1], line[3]) && vertical(line[0], line[1])) return true;
	if (parallel(line[0], line[3]) && parallel(line[1], line[2]) && vertical(line[0], line[1])) return true;
	return false;
}

int main() {
	int T;
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		vector<vector<int>> line(4, vector<int>(3, 0));
		for (int i = 0; i < 4; i++) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			//ax+by+c=0
			line[i][0] = y2 - y1;
			line[i][1] = x1 - x2;
			line[i][2] = x2*y1 - x1*y2;
		}
		bool result = judge(line);
		if (result)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}