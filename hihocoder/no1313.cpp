#include <iostream>
#include <algorithm>

using namespace std;

int k;
string cur;

int main() {
    cin >> k;
    int min_count = 101;
    int res = 0;
    for (int i = 0; i < k; i++) {
        cin >> cur;
        int count = 0, pos = -1;
        for (int j = 0; j < cur.size(); j++) {
            if (pos == -1 && cur[j] == 'o') pos = j;
            if (pos > -1 && cur[j] == 'x') count++;
        }
        min_count = min(min_count, count);
        if (pos > -1) res += (cur.size() - pos);
    }
    res += min_count;
    cout << res << endl;

    return 0;
}