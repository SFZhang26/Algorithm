#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int T, N;
ll R, x, y;

struct seg {
    ll l, r, v;
    seg(ll a, ll b, ll c) : l(a), r(b), v(c) {}
};

vector<pair<ll, ll>> location;
vector<seg> segments;

bool cmp(pair<ll, ll> p1, pair<ll, ll> p2) {
    return p1.first < p2.first;
}

bool check(ll target) {
    ll jpos = 0, cur = location[0].second;
    for (int i = 0; i < N; i++) {
        ll xi = location[i].first;
        ll num = target;

        if (segments[jpos].r < xi) return false;

        for (int j = jpos; j <= N; j++) {
            if (j == N) return true;
            if (segments[j].l > xi) {
                jpos = j;
                cur = segments[j].v;
                break;
            }
            ll cut;
            if (j == jpos) cut = cur;
            else cut = segments[j].v;
            num -= cut;
            if (num < 0) {
                jpos = j;
                cur = -num;
                break;
            }
        }

    }
    return false;
}

ll solve() {
    ll sum = 0;
    ll low = 0, high = 0;
    sort(location.begin(), location.end(), cmp);
    for (int i = 0; i < N; i++) {
        x = location[i].first;
        y = location[i].second;
        high = max(high, y);
        sum += y;
        segments.push_back(seg(x - R, x + R, y));
    }

    low = ceil(sum * 1.0 / N);

    while (low < high) {
        ll mid = low + (high - low) / 2;
        if (check(mid)) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main() {
    cin >> T;
    for (int tt = 0; tt < T; tt++) {
        location.clear();
        segments.clear();
        cin >> N >> R;
        for (int i = 0; i < N; i++) {
            cin >> x >> y;
            location.push_back(make_pair(x, y));
        }
        cout << solve() << endl;
    }
    return 0;
}