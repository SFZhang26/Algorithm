#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <bitset>

using namespace std;

typedef long long ll;

int T;
int R, C, K;

int main() {
	//open files
	ifstream f_input;
	ofstream f_output;

	f_input.open("B-large-practice.in");
	f_output.open("out_put");

	f_input >> T;
	for (int tt = 1; tt <= T; tt++) {
		f_input >> R >> C >> K;
		vector<vector<char>> grid(R + 1, vector<char>(C + 1, 'O'));
		vector<vector<ll>> dp(R + 1, vector<ll>(C + 1, 0));
		vector<vector<ll>> square(R + 1, vector<ll>(C + 1, 0));
		vector< vector< pair<ll, ll> > > stretch(R + 1, vector< pair<ll, ll> >(C + 1, make_pair(0, 0)));
		for (int i = 0; i < K; i++) {
			int a, b;
			f_input >> a >> b;
			grid[a][b] = 'X';
		}
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
				if (grid[i - 1][j - 1] == 'X') {
					stretch[i][j] = make_pair(0, 0);
					square[i][j] = 0;
				}
				else {
					stretch[i][j] = make_pair(stretch[i][j - 1].first + 1, stretch[i - 1][j].second + 1);
					square[i][j] = min(min(stretch[i][j].first, stretch[i][j].second), square[i - 1][j - 1] + 1);
					dp[i][j] += square[i][j];
				}
			}
		}
		f_output << "Case #" << tt << ": " << dp[R][C] << endl;
		cout << tt << " finished" << endl;
	}

	f_input.close();
	f_output.close();
}