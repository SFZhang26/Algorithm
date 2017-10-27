#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int s, d;

int main() {
	while (cin >> s >> d) {
		int num_s = 5 * d / (s + d);
		num_s = 2 * num_s + min(num_s, 2);

		int sum = num_s*s - (12 - num_s)*d;
		if (sum < 0) cout << "Deficit" << endl;
		else cout << sum << endl;
	}

	return 0;
}