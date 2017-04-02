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
const int SIZE = 1000001;
bool vec[SIZE] = { false };

void build() {
	int i = 2;
	while (i <= (SIZE / 2)) {
		long long int j = i;
		while ((i*j)<SIZE) {
			vec[i*j] = true;
			j++;
		}
		i++;
	}
}

int main() {
	int n;
	cin >> n;
	build();
	for (int i = 2; i <= n / 2; i++) {
		if (!vec[i] && !vec[n - i]) {
			cout << i << " " << n - i << endl;
			break;
		}
	}
	return 0;
}