#include <iostream>
#include <algorithm>

using namespace std;

const int MAXNUM = 5001;

int T, n;
pair<int, int> vec[MAXNUM];
int dp[MAXNUM];

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) return p1.second > p2.second;
    else return p1.first > p2.first;
}

int main() {
    cin >> T;
    for (int tt = 0; tt < T; tt++) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> vec[i].first >> vec[i].second;
        sort(vec, vec + n, cmp);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int pos = res;
            int cur_min = 10001;
            for (int j = pos - 1; j >= 0; j--) {
                if (dp[j] >= vec[i].second && dp[j] < cur_min) {
                    cur_min = dp[j];
                    pos = j;
                }
            }
            dp[pos] = vec[i].second;
            if (pos == res) res++;
        }
        cout << res << endl;
    }
    return 0;
}