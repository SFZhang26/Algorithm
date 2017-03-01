#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <string>
#include <set>

using namespace std;

typedef long long ll;

int T;

int main() {
	ifstream f_input;
	ofstream f_output;

	f_input.open("A-large-practice.in");
	f_output.open("out_put");



	string ctr;

	getline(f_input, ctr);
	T = atoi(ctr.c_str());

	for (int tt = 1; tt <= T; tt++) {
		int N;
		getline(f_input, ctr);
		N = atoi(ctr.c_str());
		vector<string> in;
		vector<string> longest;
		vector<int> count;
		int max_num = 0;
		for (int i = 0; i < N; i++) {
			string cur;
			getline(f_input, cur);
			in.push_back(cur);
			set<char> temp;
			for (int j = 0; j < cur.size(); j++) {
				if (cur[j] != ' ') temp.insert(cur[j]);
			}
			count.push_back(temp.size());
			int size = temp.size();
			max_num = max(max_num, size);
		}
		/*for (int i = 0; i < in.size(); i++) {
			cout << in[i] << endl;
		}*/
		for (int i = 0; i < N; i++) {
			if (max_num == count[i]) {
				longest.push_back(in[i]);
			}
		}
		sort(longest.begin(), longest.end());
		f_output << "Case #" << tt << ": " << longest[0] << endl;
	}

	f_input.close();
	f_output.close();
}