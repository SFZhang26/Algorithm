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

const int N = 30001;

bitset<N> b[N][5];
int Rank[N][5], help[N][5];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> Rank[i][j];
			help[Rank[i][j]][j] = i;
		}
	}

	for (int j = 0; j < 5; j++) {
		for (int i = 2; i <= n; i++) {
			b[i][j] = b[i - 1][j];
			b[i][j].set(help[i - 1][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		bitset<N> res = b[Rank[i][0]][0];
		for (int j = 1; j < 5; j++) {
			res &= b[Rank[i][j]][j];
		}
		cout << res.count() << endl;
	}

	return 0;
}