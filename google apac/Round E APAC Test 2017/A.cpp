#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
#include <stdlib.h>
#include <fstream>
//#include <fiostream.h> 

using namespace std;

typedef long long ll;
int T;

int main() {
	/*FILE *fin, *fout;
	fin=fopen("D-large-practice.in", "r");
	fout = fopen("output", "w");*/
	ifstream fin("A-large-practice.in");
	ofstream fout("output");

	fin >> T;
	for (int k = 1; k <= T; k++) {
		string pat = "";
		fin >> pat;
		ll a, b;
		fin >> a >> b;

		int size = pat.size();
		int num = 0;
		for (int i = 0; i < pat.size(); i++) {
			if (pat[i] == 'B') num++;
		}
		ll yu = (b - a + 1) % size;
		ll count = (b - a + 1) / size;
		ll result = num*count;
		ll cur = (a - 1) % size;
		for (int i = 1; i <= yu; i++) {
			if (pat[cur] == 'B') result++;
			cur = (cur + 1) % size;
		}
		fout << "Case #" << k << ": " << result << endl;
	}

}