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

bool solve(string str) {
	int con = 1, samePre = 1, sameCur = 1, sameNUM = 1;
	int k = 0;
	char former = str[0];
	while ((k + 1)<str.size()&&str[k + 1] == former) {
		k++;
		samePre++;
	}
	if (k == (str.size() - 1)) return false;
	for (int j = k + 1; j < str.size(); j++) {
		char curr = str[j];
		while ((j + 1)<str.size() && str[j + 1] == curr) {
			j++;
			sameCur++;
		}
		if ((curr - former) == 1 && sameCur <= samePre&&con == 1) {
			con++;
			samePre = sameCur;
			sameCur = 1;
		}
		else if ((curr - former) == 1 && sameCur < samePre&&con == 2) {
			samePre = sameCur;
			sameCur = 1;
			con = 2;
		}
		else if ((curr - former) == 1 && sameCur >= samePre&&con == 2) {
			return true;
		}
		else if ((curr - former) == 1 && sameCur > samePre) {
			con = 1;
			samePre = sameCur;
			sameCur = 1;
		}
		else if ((curr - former) != 1) {
			con = 1;
			samePre = sameCur;
			sameCur = 1;
		}
		former = curr;
		if (j == (str.size() - 1)) return false;
	}
}


int main() {
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		int n;
		string str;
		cin >> n >> str;
		bool result = solve(str);
		if (result) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}