#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

errno_t err;
FILE *f_input, *f_output;

int T;
const int N = 2001;

double dp[N][N] = {0};

int main() {
	for (int i = 1; i < N; i++) dp[i][0] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < i; j++) {
			double p1 = (double)i / (i + j);
			double p2 = 1 - p1;
			dp[i][j] = dp[i - 1][j] * p1 + dp[i][j - 1] * p2;
		}
	}

	//open files
	err = fopen_s(&f_input, "A-large-practice.in", "r");
	err = fopen_s(&f_output, "out_put", "w");

	//read
	fscanf_s(f_input, "%d", &T);

	for (int i = 1; i <= T; i++) {
		int a, b;
		fscanf_s(f_input, "%d %d", &a, &b);
		fprintf(f_output, "Case #%d: %.8f\n", i, dp[a][b]);
	}
}