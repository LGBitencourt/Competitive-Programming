#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int vdp[5005];
string s;
int n;

long long dp(int i) {
    if (i == n) return 1;
    if (i > n || s[i] == '0') return 0;
    if (vdp[i] != 0) return vdp[i];
    if ((s[i] == '2' && s[i + 1] > '6') || (s[i] > '2'))
        return vdp[i] = dp(i + 1);
    else
        return vdp[i] = dp(i + 1) + dp(i + 2);
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> s, s.compare("0") != 0) {
        n = s.length();
        memset(vdp, 0, sizeof vdp);
        cout << dp(0) << '\n';
    }
}
