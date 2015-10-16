#include <iostream>
#include <string>

#define MAIOR 1
#define IGUAL 0

using namespace std;

typedef long long int lli;

int n;
string w, x;

lli solve (int i, int flag) {
    if (i == n && flag == IGUAL) return 0;
    if (i == n && flag == MAIOR) return 1;
    if (w[i] != '?') {
        if (w[i] < x[i] && flag == IGUAL) return 0;
        if (w[i] < x[i] && flag == MAIOR) return solve(i+1, MAIOR);
        if (w[i] == x[i]) return solve (i + 1, flag);
        if (w[i] > x[i]) return solve (i + 1, MAIOR);
    } else {
        if (flag == MAIOR) return 10 * solve (i + 1, flag);
        else return solve (i + 1, flag) + ('9' - x[i]) * solve (i + 1, MAIOR);
    }
}

int main () {
    ios::sync_with_stdio(false);
    while (cin >> w && w != "#") {
        cin >> x;
        n = w.length();
        cout << solve (0, IGUAL) << '\n';
    }
}
