#include <cstdio>
#include <cstring>
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
const int MAX = 1e6 + 1;
int N, P, Q;

double dp[MAX][101];

// TLE
double solve(int n, int p) {
	if (n == 0) return 0;
	if (p >= 100) return solve(n - 1, P / pow(2, N - n + 1)) + 1;
	if (dp[n][p] > 0) return dp[n][p];

	double left, right;
	left = (p / 100.0)*(solve(n - 1, P / pow(2, N - n + 1)) + 1);
	right = ((100 - p) / 100.0)*(solve(n, p + Q) + 1);
	dp[n][p] = left + right;
	return dp[n][p];
}

int main() {
	scanf("%d %d %d", &P, &Q, &N);
	double res = 0;
	for (int i = 0; i < N; i++) {
		double cur = 0;
		double p = 1.0;
		int cur_p = P;
		int count = 1;
		while (true) {
			cur += (count*p*cur_p / 100.0);
			count++;
			p = p*(100 - cur_p) / 100.0;
			cur_p += Q;
			if (cur_p >= 100) {
				cur += count*p;
				break;
			}
		}
		P /= 2;
		res += cur;
	}
	printf("%.2f\n", res);
	return 0;
}