#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>

using namespace std;

typedef long long ll;

ll T;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll r = exgcd(b, a%b, x, y);
	ll t = x;
	x = y;
	y = t - a / b*y;
	return r;
}
// ax+by=c 的整数解(x_i,y_i)个数
ll getAnswerNum(ll a, ll b, ll c) {
	ll gcd_ab = gcd(a, b);
	if (c%gcd_ab != 0) return 0;
	ll p0, q0;
	exgcd(a, b, p0, q0);
	p0 *= c / gcd_ab;
	q0 *= c / gcd_ab;
	ll result = 0;
	result -= floor((double)(-p0)*gcd_ab / b);
	result += floor((double)(q0)*gcd_ab / a);
	if (q0*gcd_ab%a == 0) result--;
	return result<0 ? 0 : result;
}

ll solve(ll n, ll d) {
	ll result = 0;
	for (ll i = 1; 2 * i * d <= n; i++) {
		ll first = d*i;
		if (n%first == 0) result++;
		for (ll j = 1; first*j < n; j++) {
			result += getAnswerNum(first + 1, first + 2, n - first*j);
		}
		result += getAnswerNum(first, first + 1, n);
		result += getAnswerNum(first, first + 2, n);
	}
	return n%d == 0 ? result + 1 : result;
}

int main() {
	//open files
	ifstream f_input;
	ofstream f_output;

	f_input.open("C-large-practice.in");
	f_output.open("out_put");

	f_input >> T;

	for (ll k = 1; k <= T; k++) {
		ll n, d;
		f_input >> n >> d;
		ll result = solve(n, d);
		f_output << "Case #" << k << ": " << result << endl;
	}
	f_input.close();
	f_output.close();
}