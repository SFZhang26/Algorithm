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

//x可能为实数
//x>0 x<1
//应返回 2
int main() {
	int N;
	cin >> N;
	vector<int> vec;
	vector<string> oper;
	for (int i = 0; i < N; i++) {
		string X, operat;
		int c;
		cin >> X >> operat >> c;
		oper.push_back(operat);
		vec.push_back(c);
	}
	int result = 0;
	for (double i = -1; i < 1001; i+=0.5) {
		int cur = 0;
		for (int j = 0; j < N; j++) {
			if (oper[j] == "="&&i == vec[j]) cur++;
			else if (oper[j] == ">"&&i > vec[j]) cur++;
			else if (oper[j] == ">="&&i >= vec[j]) cur++;
			else if (oper[j] == "<"&&i < vec[j]) cur++;
			else if(oper[j] == "<="&&i <= vec[j]) cur++;
		}
		result = max(result, cur);
	}
	cout << result << endl;
	return 0;
}