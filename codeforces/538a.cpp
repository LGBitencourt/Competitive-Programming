#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string cf = "CODEFORCES";
    string s;
    int n, sum = 0, m = 0;
    cin >> s;

    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == cf[9-m]) sum++, m++;
        else break;
    }
    for (int i = 0; i < 10; i++) {
        if (s[i] == cf[i]) sum++;
        else break;
    }

    if (sum >= 10) cout << "YES\n";
    else cout << "NO\n";

}
