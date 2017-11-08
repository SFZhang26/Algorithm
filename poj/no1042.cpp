#include <iostream>

using namespace std;

int n;
int h;
int f[30], d[30], t[30], fish_left[30], time_stay[30], solution[30], cur_sol[30];
int res;

int main() {
	while (cin >> n) {
		if (n == 0) break;
		cin >> h;
		for (int i = 0; i < n; i++) {
			cin >> f[i];
		}
		for (int i = 0; i < n; i++) cin >> d[i];
		for (int i = 0; i < n - 1; i++) cin >> t[i];

		h *= 12;
		res = 0;
		memset(solution, 0, sizeof(solution));
		int time_road = 0;
		for (int i = 0; i < n; i++) {
			int fish_get = 0;
			int time_left = h - time_road;
			for (int j = 0; j < n; j++) {
				fish_left[j] = f[j];
				cur_sol[j] = 0;
			}

			while (time_left > 0) {
				int biggest = -1, index = -1;
				for (int j = 0; j <= i; j++) {
					if (fish_left[j] > biggest) {
						biggest = fish_left[j];
						index = j;
					}
				}
				if (biggest <= 0) {
					cur_sol[0] += time_left;
					break;
				}
				fish_get += biggest;
				cur_sol[index] ++;
				fish_left[index] -= d[index];
				time_left--;
			}
			if (fish_get > res) {
				res = fish_get;
				for (int j = 0; j < n; j++) solution[j] = cur_sol[j];
			}
			else if (fish_get == res) {
				for (int j = 0; j <= i; j++) {
					if (cur_sol[j] > solution[j]) {
						for (int k = j; k <= i; k++) solution[k] = cur_sol[k];
						break;
					}
					else if (cur_sol[j] < solution[j]) break;
				}
			}
			time_road += t[i];
			if (time_road > h) break;
		}
		for (int i = 0; i < n - 1; i++) cout << solution[i] * 5 << ", ";
		cout << solution[n - 1] * 5 << endl;
		cout << "Number of fish expected: " << res << endl << endl;
	}
	
	return 0;
}