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

using namespace std;

typedef long long ll;

ll MOD = 19999997;
struct matrix{
	ll a, b, c, d;
	matrix(int aa, int bb, int cc, int dd) :a(aa), b(bb), c(cc), d(dd){};
};

matrix mul(matrix m1, matrix m2) {
	matrix m(0,0,0,0);
	m.a = (m1.a*m2.a + m1.b*m2.c) % MOD;
	m.b = (m1.a*m2.b + m1.b*m2.d) % MOD;
	m.c = (m1.c*m2.a + m1.d*m2.c) % MOD;
	m.d = (m1.c*m2.b + m1.d*m2.d) % MOD;
	return m;
}

int main() {
	unsigned int n;
	cin >> n;

	bitset<32> bitvec(n);
	//cout << bitvec << endl;

	matrix a_n(1, 0, 0, 1), temp(0, 1, 1, 1);

	for (int i = 0; i < 32; i++) {
		if (bitvec[i]) {
			a_n = mul(a_n, temp);
		}
		temp = mul(temp, temp);
	}
	cout << a_n.d%MOD << endl;

	return 0;
}