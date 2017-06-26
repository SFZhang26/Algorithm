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

const int MAX = 1e5 + 1;
int heap[MAX];
int num = 0;
int n;

void push(int x) {
	int k = ++num;
	while (k > 1) {
		int index = k / 2;
		if (heap[index] < x) heap[k] = heap[index];
		else break;
		k = index;
	}
	heap[k] = x;
}

int top() {
	return heap[1];
}

void max_heapify(int i) {
	int l = 2 * i;
	int r = l + 1;
	int large;
	if (l <= num && heap[l] > heap[i]) large = l;
	else large = i;
	if (r <= num && heap[r] > heap[large]) large = r;

	if (large != i) {
		int temp = heap[large];
		heap[large] = heap[i];
		heap[i] = temp;
		max_heapify(large);
	}
}

void pop() {
	heap[1] = heap[num--];
	max_heapify(1);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a;
		int tmp;
		cin >> a;
		if (a == 'A') {
			cin >> tmp;
			push(tmp);
		}
		else {
			cout << top() << endl;
			pop();
		}
	}
	return 0;
}