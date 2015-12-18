#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

pli mdp[1005][1005];
int cash[2][1005];
string os[2][1005];
int n, m;

pli dp (int i, int j) {
    if (i == n || j == m) return pli(0, 0);
    if (mdp[i][j].first != -1) return mdp[i][j];
    pli a1, a2;
    a1 = dp (i+1, j), a2 = dp (i, j+1);
    if (a2.first > a1.first) a1 = a2;
    else if (a1.first == a2.first)
        if (a2.second < a1.second) a1 = a2;
    if (os[0][i].compare(os[1][j]) == 0) {
        a2 = dp (i+1, j+1);
        a2.first += (ll) cash[0][i] + cash[1][j], a2.second++;
        if (a2.first > a1.first) a1 = a2;
        else if (a1.first == a2.first)
            if (a2.second < a1.second)
                a1 = a2;
    }
    return mdp[i][j] = a1;
}

int main () {
    ios::sync_with_stdio(false);
    int tc;
    string trash;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> trash >> os[0][i] >> cash[0][i];
        cin >> m;
        for (int i = 0; i < m; i++)
            cin >> trash >> os[1][i] >> cash[1][i];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                mdp[i][j] = pli(-1, -1);
        pli ans = dp (0, 0);
        cout << ans.first << ' ' << ans.second << endl;
    }
}
