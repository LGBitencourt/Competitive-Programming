#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<string, int> psi;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
////////////////0123456789
const int MAX = 10005;
const int modn = 1000000007;

psi ans[2][10005];
bool can[10005];
vector<psi> l[10005];

bool cmp (psi a, psi b) {
    if (a.ss != b.ss) return a.ss > b.ss;
    string tmp = a.ff, tmp2 = b.ff;
    return tmp[0] < tmp2[0];
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, reg, point;
    char name[15];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> name >> reg >> point;
        l[reg].pb (psi(name, point));
    }
    for (int i = 1; i <= m; i++) {
        can[i] = true;
        int p1, p2;
        p1 = p2 = INT_MIN;
        ans[0][i] = psi("?", INT_MIN);
        ans[1][i] = psi("?", INT_MIN);
        sort (l[i].begin(), l[i].end(), cmp);

        for (int j = 0; j < l[i].size(); j++) {
            if (l[i][j].ss > p1) {
                if (p1 > p2) p2 = p1;
                p1 = l[i][j].ss;
            } else if (l[i][j].ss > p2) p2 = l[i][j].ss;
        }

        for (int j = 0; j < l[i].size(); j++) {
            if (l[i][j].ss > ans[0][i].ss) ans[0][i] = l[i][j];
            else if (l[i][j].ss > ans[1][i].ss) ans[1][i] = l[i][j];
            else if (l[i][j].ss == p1 || l[i][j].ss == p2) can[i] = false;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (!can[i]) cout << "?\n";
        else cout << ans[0][i].ff << " " << ans[1][i].ff << "\n";
    }
}

