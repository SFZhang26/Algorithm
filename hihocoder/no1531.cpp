#include <cstdio>
#include <cstring>
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

int n, k;
int u, x;

int pic[7]; //fruit + animal
vector<vector<int>> history(11, vector<int>(7, 0));
vector<ll> card(10, 1e7);
ll card_num = 0;
int turn = 0;

void reset() {
	for (int i = 0; i < 7; i++) pic[i] = 0;
	card_num = 0;
	history = vector<vector<int>>(11, vector<int>(7, 0));
}

bool judge() {
	for (int i = 0; i < 4; i++) {
		if (pic[i] == 5) return true;
	}
	if (pic[4]>0 && (pic[0]>0 || pic[1]>0 || pic[2]>0) && pic[3] == 0) {
		return true;
	}
	if (pic[5] > 0 && (pic[0] > 0 || pic[3] > 0 || pic[2] > 0) && pic[1] == 0) {
		return true;
	}
	if (pic[6] > 0 && (pic[0] > 0 || pic[1] > 0 || pic[2] > 0 || pic[3]>0)) {
		return true;
	}
	return false;
}

void bell(int index) {
	if (judge()) {
		card[index] += card_num;
		reset();
	}
	else {
		for (int i = 0; i < n; i++) {
			card[i]++;
		}
		card[index] -= n;
	}
	turn = u;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		char s[10];
		scanf("%s %d", s, &u);
		if (strcmp(s, "Fruit") == 0) {
			card_num++;
			card[turn]--;
			vector<int> cur(7, 0);
			for (int j = 0; j < u; j++) {
				scanf("%d", &x);
				cur[x] ++;
			}
			for (int j = 0; j < 7; j++) {
				pic[j] += (cur[j] - history[turn][j]);
			}
			history[turn] = cur;
			turn = (turn + 1) % n;
		}
		else if (strcmp(s, "Animal") == 0) {
			card_num++;
			card[turn]--;
			for (int j = 0; j < 7; j++) {
				pic[j] -= history[turn][j];
				history[turn][j] = 0;
			}
			history[turn][4 + u] = 1;
			pic[4 + u] ++;
			turn = (turn + 1) % n;
		}
		else {
			bell(u);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << card[i] << endl;
	}

	return 0;
}