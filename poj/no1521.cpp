#include <iostream>
#include <string>
#include <queue>
#include <iomanip>

using namespace std;

string str;
int counts[256];
priority_queue<int, vector<int>, greater<int>> que;

void solve() {
    int n = str.size();
    int sum = 0;
    for (int i = 0; i < 256; i++) counts[i] = 0;
    for (int i = 0; i < n; i++) counts[str[i]]++;
    for (int i = 0; i < 256; i++) if (counts[i]>0) que.push(counts[i]);
    while (!que.empty()) {
        int v1 = que.top();
        que.pop();
        if (que.empty()) {
            if (sum == 0) sum = v1;
            break;
        }
        int v2 = que.top();
        que.pop();
        sum += (v1 + v2);
        que.push(v1 + v2);
    }
    cout << n * 8 << " " << sum << " " << fixed << setprecision(1) << n * 8.0 / sum << endl;
}

int main() {
    while (cin >> str) {
        if (str == "END") break;
        else solve();
    }
    return 0;
}