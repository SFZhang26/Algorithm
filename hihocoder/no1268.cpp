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

vector<int> r1 = { 4, 9, 2, 7, 6, 1, 8, 3 };
vector<int> r2 = { 4, 3, 8, 1, 6, 7, 2, 9 };

vector<int> getClockWise(vector<vector<int>> input) {
	vector<int> vec(8, 0);
	vec[0] = input[0][0];
	vec[1] = input[0][1];
	vec[2] = input[0][2];
	vec[3] = input[1][2];
	vec[4] = input[2][2];
	vec[5] = input[2][1];
	vec[6] = input[2][0];
	vec[7] = input[1][0];
	return vec;
}

vector<vector<int>> check(vector<int> seq) {
	vector<vector<int>> result;
	for (int i = 0; i < 8; i += 2) {
		vector<int> cur;
		int j = 0;
		for (; j < 8; j++) {
			cur.push_back(r1[(i + j) % 8]);
			if (seq[j] == 0) continue;
			else if (seq[j] != r1[(i + j) % 8]) break;
		}
		if (j == 8) {
			result.push_back(cur);
		}
		if (result.size() > 1) return result;
	}
	for (int i = 0; i < 8; i += 2) {
		vector<int> cur;
		int j = 0;
		for (; j < 8; j++) {
			cur.push_back(r2[(i + j) % 8]);
			if (seq[j] == 0) continue;
			else if (seq[j] != r2[(i + j) % 8]) break;
		}
		if (j == 8) {
			result.push_back(cur);
		}
		if (result.size() > 1) return result;
	}
	return result;
}

void printMatrix(vector<int> vec) {
	cout << vec[0] << " " << vec[1] << " " << vec[2] << endl;
	cout << vec[7] << " " << 5 << " " << vec[3] << endl;
	cout << vec[6] << " " << vec[5] << " " << vec[4] << endl;
}

int main() {
	vector<vector<int>> input(3, vector<int>(3, 0));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> input[i][j];
		}
	}
	vector<int> seq = getClockWise(input);
	vector<vector<int>> result = check(seq);
	if (result.size()>1) cout << "Too Many" << endl;
	else printMatrix(result[0]);

	return 0;
}