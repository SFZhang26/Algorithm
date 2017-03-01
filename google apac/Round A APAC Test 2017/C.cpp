#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <iomanip>

using namespace std;

typedef long long ll;

ll T;

double delta = 1e-10;



double get(vector<ll> c, double r) {
	double sum = 0;
	for (int i = 0; i < c.size(); i++) {
		sum = sum*(1 + r) + c[i];
	}
	return sum;
}

double solve(vector<ll> c) {
	double low = -1.0, high = 1.0;
	while (abs(high - low) >= delta) {
		double mid = (low + high) / 2.0;
		double cur = get(c, mid);
		//cout << "mid: "<< mid <<" value:  "<<cur << endl;
		if (cur>0) low = mid;
		else high = mid;
	}
	return (low + high) / 2.0;
}

int main() {
	//open files
	ifstream f_input;
	ofstream f_output;

	f_input.open("C-large-practice.in");
	f_output.open("out_put");

	f_input >> T;

	for (int tt = 1; tt <= T; tt++) {
		int M;
		f_input >> M;
		vector<ll> c;
		for (int i = 0; i <= M; i++) {
			ll cur;
			f_input >> cur;
			c.push_back(cur);
		}
		c[0] = -c[0];
		double result = solve(c);
		f_output << "Case #" << tt << ": ";
		f_output.setf(ios::fixed, ios::floatfield);
		f_output << setprecision(12);
		f_output << result << endl;
	}

	f_input.close();
	f_output.close();
}