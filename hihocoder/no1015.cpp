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

vector<int> getNext(string pattern) {
	int n = pattern.size();
	vector<int> next(n + 1, 0);
	int j = 0;
	for (int i = 1; i < n; i++) {
		while (j>0 && pattern[i] != pattern[j]) j = next[j];
		
		if (pattern[i] == pattern[j]) 
			j++;
		
		next[i + 1] = j;
	}
	return next;
}


int main() {
	int T;
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		string pattern, origin;
		cin >> pattern >> origin;
		vector<int> next = getNext(pattern);
		int result = 0;
		int j = 0;
		for (int i = 0; i < origin.size(); i++) {
			while (j > 0 && origin[i] != pattern[j]) j = next[j];

			if (origin[i] == pattern[j]) j++;

			if (j == pattern.size()) {
				result++;
				j = next[j];
			}
		}
		cout << result << endl;
	}
	return 0;
}