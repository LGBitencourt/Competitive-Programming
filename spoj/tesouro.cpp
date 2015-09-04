#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

int x, y, total, n, ans;
int tesouro[150];
int mpd[105][10005];

int pd (int i, int v) {
    if (v == 0 || ans != 0) return 1;
    if (i == n || v < 0) return 0;
    if (mpd[i][v] != -1) return mpd[i][v];
    if (pd(i + 1, v - tesouro[i]))
        return mpd[i][v] = 1;
    if (pd(i + 1, v))
        return mpd[i][v] = 1;
    return mpd[i][v] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    while (cin >> x >> y >> n, x != 0) {
        total = ans = 0;

        for (int i = 0; i < n; i++) {
            cin >> tesouro[i];
            total += tesouro[i];
        }
        sort(tesouro, tesouro + n);
        total += x + y;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= (total/2) - x; j++)
                mpd[i][j] = -1;
        cout << "Teste " << t++ << '\n';
        if (total&1) {
            cout << "N\n";
        } else {
            if (pd(0, (total/2) - x))
                cout << "S\n";
            else
                cout << "N\n";
        }
        cout << '\n';
    }
}
