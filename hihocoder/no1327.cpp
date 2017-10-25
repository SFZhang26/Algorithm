#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

const int LEN = 26;
string s;
ll count[LEN];

string solve() {
    for(int i=0;i<LEN;i++) count[i]=0;
    for(int i=0;i<s.size();i++) count[s[i]-'a']++;
    string res = "";
    char pre = '0';
    char next = '0';
    for(int i=0;i<s.size();i++) {
        int pos = -1;
        for(int j = 0;j<LEN;j++) {
            char cur = char('a' + j);
            if (pos == -1 && count[j] > 0 && pre != cur) {
                pos = j;
                next = cur;
            }
            int size = s.size() - i;
            if (count[j] > size/2) {
                if (pre == cur) {
                    return "INVALID";
                }
                else {
                    pos = j;
                    next = cur;
                    break;
                }
            }
        }
        count[pos]--;
        res += next;
        pre = next;
    }
    return res;
}

int main() {
    cin >> s;
    cout << solve() <<endl;
    return 0;
}