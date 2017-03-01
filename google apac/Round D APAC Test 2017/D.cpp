#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

typedef long long ll;
int T;

int main() {
	FILE *fin, *fout;
	fin=fopen("D-large-practice.in", "r");
	fout = fopen("output", "w");

	fscanf(fin, "%d", &T);
	for (int kk = 1; kk <= T; kk++) {
		int num, money, length;
		fscanf(fin, "%d %d %d", &num, &money, &length);

		vector<ll> dp(length + 1, INT_MAX);
		dp[0] = 0;
		for (ll i = 0; i < num; i++) {
			int a, b;
			int p;
			fscanf(fin, "%d %d %d", &a, &b, &p);

			//寻找长度为b-a+1的sliding window中最小值的下标 记录到que中
			vector<int> que(length + 1, 0);
			int start = 0;
			int end = 0;
			for (int k = a; k < b&&length - k >= 0; k++) {
				while (end > start && dp[que[end - 1]] >= dp[length - k]) end--;
				que[end++] = length - k;
			}

			for (ll j = length; j >= 0; j--) {
				if (j - b >= 0) {
					while (end > start && dp[que[end - 1]] >= dp[j - b]) end--;
					que[end++] = j - b;
				}
				if (start < end) dp[j] = min(dp[j], dp[que[start]] + p);

				if (dp[start] >= j - a) start++;
			}
		}
		if (dp[length] <= money)
			fprintf(fout, "Case #%d: %d\n", kk, dp[length]);
		else fprintf(fout, "Case #%d: IMPOSSIBLE\n", kk);
	}	
}