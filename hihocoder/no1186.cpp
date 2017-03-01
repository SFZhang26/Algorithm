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

vector<int> get(int n) {
	vector<int> result;
	for (int i = 1; i <= n; i++) {
		if (n%i == 0) result.push_back(i);
	}
	return result;
}


int main() {
	int p, q;
	cin >> p >> q;
	vector<int> pp = get(p);
	vector<int> qq = get(q);
	for (int i = 0; i < pp.size(); i++) 
	for (int j = 0; j < qq.size(); j++)
		cout << pp[i] << " " << qq[j] << endl;


	return 0;
}