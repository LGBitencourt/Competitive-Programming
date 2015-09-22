#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int mpd[2005][2005];
string a, b;

int pd (int i, int j) {
    if (a[i] == '\0' && b[j] == '\0')
        return 0;
    if (mpd[i][j] != -1) return mpd[i][j];

    if (a[i] == '\0')
        mpd[i][j] = 1 + pd(i, j + 1);
    else if (b[j] == '\0')
        mpd[i][j] = 1 + pd(i + 1, j);
    else if (a[i] == b[j])
        mpd[i][j] = pd (i + 1, j + 1);
    else
        mpd[i][j] = 1 + min(pd(i + 1, j + 1), min(pd(i + 1, j), pd(i, j + 1)));
    return mpd[i][j];
}

int main () {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        memset(mpd, -1, sizeof mpd);
        cin >> a >> b;
        cout << pd(0, 0) << '\n';
    }
}
