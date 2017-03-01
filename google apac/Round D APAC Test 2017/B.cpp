#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

errno_t err;
FILE *f_input, *f_output;

int T;

int main() {
	//open files
	err = fopen_s(&f_input, "B-large-practice.in", "r");
	err = fopen_s(&f_output, "out_put", "w");

	fscanf_s(f_input, "%d", &T);

	for (int i = 1; i <= T; i++) {
		int r, c;
		ll result;
		fscanf_s(f_input, "%d %d", &r, &c);
		if (r == 2) result = 2 * (c - c / 3);
		else if (c == 2) result = 2 * (r - r / 3);
		else if (c % 3 == 0) result = r*c - (c / 3)*r;
		else if (c % 3 == 1) result = r*c - (c / 3)*r - r / 3;
		else result = r*c - (c / 3)*r - r / 3 - (r + 1) / 3;
		fprintf(f_output, "Case #%d: %d\n", i, result);
	}

}