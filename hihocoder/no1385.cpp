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
#include <sstream>

using namespace std;

typedef long long ll;

int T;

void output(map<string,int> count) {
	int big = 0;
	string result = "";
	for (map<string, int>::iterator it = count.begin(); it != count.end(); it++) {
		if (it->second > big) {
			big = it->second;
			result = it->first;
		}
	}
	cout << result << ":" << big << endl;
}

void cal(map<string, int> &count, string line) {
	line = line + ".";
	int start = 0;
	string prev = "";
	string cur = "";
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == ',' || line[i] == '.' || line[i] == ' ') {
			if (start < i) {
				cur = line.substr(start, i - start);
				if (prev != "") {
					string phase = prev + " " + cur;
					count[phase]++;
				}
			}
			start = i + 1;
			if (line[i] == ' ') {
				prev = cur;
			}
			else {
				prev = "";
				cur = "";  //IMPORTANT  a b a, b a c a c
			}
		}
	}
}

int main() {
	string line;
	map<string, int> count;
	while (getline(cin, line)) {
		//cout << line << endl;
		if (line == "####") {
			output(count);
			count.clear();
		}
		else {
			cal(count, line);
		}
	}
	return 0;
}