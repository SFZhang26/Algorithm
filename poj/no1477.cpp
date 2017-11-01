#include <iostream>

using namespace std;

int n;
int a[51];

int main() {
	int cas = 0;
	while (cin >> n) {
		cas++;
		if (n == 0) break;
		else {
			int average = 0, res = 0;
			for (int i = 0; i < n; i++) {
				cin >> a[i];
				average += a[i];
			}
			average /= n;
			for (int i = 0; i < n; i++) res += (a[i]>average ? a[i] - average : 0);
			cout << "Set #" << cas << endl;
			cout << "The minimum number of moves is " << res << "." << endl << endl;
		}
	}
	

	return 0;
}