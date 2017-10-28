#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, gray;
int vec[12];

bool cmp(int a, int b) {
    return a > b;
}

int solve() {
    int max_num = 0;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        max_num = max(max_num, vec[i]);
    }
    cin >> gray;
    int res = ceil(max_num / 50.0);
    for (int i = 0; i < n; i++) vec[i] = res * 50 - vec[i];
    double g = 0;
    while (g < gray) {
        sort(vec, vec + n, cmp);
        if (vec[2] == 0) {
            for (int i = 0; i < n; i++) vec[i] += 50;
            res++;
        } else {
            vec[0]--;
            vec[1]--;
            vec[2]--;
            g++;
        }
    }
    return res;
}

int main() {
    while (cin >> n) {
        if (n == 0) break;
        else cout << solve() << endl;
    }
    return 0;
}