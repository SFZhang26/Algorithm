#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

typedef long long ll;

int T;

int R, C, Rs, Cs, S;
double p;
double q;
double result = 0;

void solve(double cur, int i, int j, int step, vector<vector<char>>game, vector<vector<int>> visited) {
	if (step == 0) {
		result = max(result, cur);
		return;
	}
	if (i - 1 >= 0) {
		visited[i - 1][j]++;
		if (game[i - 1][j] == '.') solve(cur + pow((1 - q), (double)(visited[i - 1][j]) - 1)*q, i - 1, j, step - 1, game, visited);
		else solve(cur + pow((1 - p), (double)(visited[i - 1][j]) - 1)*p, i - 1, j, step - 1, game, visited);
		visited[i - 1][j]--;
	}
	if (j - 1 >= 0) {
		visited[i][j - 1]++;
		if (game[i][j - 1] == '.') solve(cur + pow((1 - q), (double)(visited[i][j - 1]) - 1)*q, i, j - 1, step - 1, game, visited);
		else solve(cur + pow((1 - p), (double)(visited[i][j - 1]) - 1)*p, i, j - 1, step - 1, game, visited);
		visited[i][j - 1]++;
	}

	if (i + 1 < R) {
		visited[i + 1][j]++;
		if (game[i + 1][j] == '.') solve(cur + pow((1 - q), (double)(visited[i + 1][j]) - 1)*q, i + 1, j, step - 1, game, visited);
		else solve(cur + pow((1 - p), (double)(visited[i + 1][j]) - 1)*p, i + 1, j, step - 1, game, visited);
		visited[i + 1][j]--;
	}

	if (j + 1 <C) {
		visited[i][j + 1]++;
		if (game[i][j + 1] == '.') solve(cur + pow((1 - q), (double)(visited[i][j + 1]) - 1)*q, i, j + 1, step - 1, game, visited);
		else solve(cur + pow((1 - p), (double)(visited[i][j + 1]) - 1)*p, i, j + 1, step - 1, game, visited);
		visited[i][j + 1]++;
	}
}


int main() {
	ifstream f_input;
	ofstream f_output;

	f_input.open("A-large-practice.in");
	f_output.open("out_put");

	f_input >> T;
	for (int tt = 1; tt <= T; tt++) {
		result = 0;
		f_input >> R >> C >> Rs >> Cs >> S;
		f_input >> p >> q;
		vector<vector<char>> game(R, vector<char>(C, '.'));
		for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			f_input >> game[i][j];

		vector<vector<int>> visited(R, vector<int>(C, 0));
		solve(0, Rs, Cs, S, game, visited);
		f_output << "Case #" << tt << ": ";
		f_output.setf(ios::fixed, ios::floatfield); 
		f_output << setprecision(7);
		f_output<< result << endl;
		cout << tt << "finished" << endl;
	}
	f_input.close();
	f_output.close();
}