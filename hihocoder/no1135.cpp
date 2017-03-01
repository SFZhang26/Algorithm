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

using namespace std;

typedef long long ll;

int T;

bool vanish(int a,int b,int c,int x,int y,int z) {
	if (abs(a - b) == x&&abs(a - c) == y&&abs(b - c) == z) return true;
	else if (abs(a - b) == x&&abs(b - c) == y&&abs(a - c) == z) return true;
	else if (abs(a - c) == x&&abs(a - b) == y&&abs(b - c) == z) return true;
	else if (abs(a - c) == x&&abs(b - c) == y&&abs(a - b) == z) return true;
	else if (abs(b - c) == x&&abs(a - b) == y&&abs(a - c) == z) return true;
	else if (abs(b - c) == x&&abs(a - c) == y&&abs(a - b) == z) return true;
	else return false;
}


int main() {
	int x, y, z;
	cin >> x >> y >> z;
	string str;
	cin >> str;
	int a = 0, b = 0, c = 0;
	int result = 0;
	int cur = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'R') a++;
		else if (str[i] == 'Y') b++;
		else if (str[i] == 'B')c++;
		cur++;
		result = max(result, cur);
		if (vanish(a, b, c, x, y, z)) {
			cur = 0;
			a = 0;
			b = 0;
			c = 0;
		}
	}
	cout << result << endl;
	
	return 0;
}