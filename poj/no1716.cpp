#include <iostream>
#include <algorithm>
using namespace std;

int n, a, b;
pair<int, int> vec[10001];
int choose[20002];

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second < p2.second;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		vec[i] = make_pair(a, b);
	}
	sort(vec, vec + n, cmp);
	choose[0] = vec[0].second - 1;
	choose[1] = vec[0].second;
	int res = 2;
	for (int i = 1; i < n; i++) {
		int count = 0;
		if (vec[i].first>choose[res - 1]) {
			choose[res++] = vec[i].second - 1;
			choose[res++] = vec[i].second;
		}
		else if (vec[i].first > choose[res - 2]) {
			choose[res++] = vec[i].second;
		}
	}
	cout << res << endl;
	return 0;
}