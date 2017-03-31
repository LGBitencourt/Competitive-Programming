#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
/////////////////0123456789
const int MAXN = 1000004;

int n, f, m;
ll a, b, c;
ll t[MAXN];
set<int> team[MAXN];

void set_t() {
    t[1] = a;
    for (int i = 2; i <= n; i++)
        t[i] = (b * t[i-1] + c) % f;
    for (int i = 1; i <= n; i++)
        team[t[i]].insert(i);
}

pii query(int i, int e) {
    if (!team[e].size()) return pii(n, n);
    auto l = team[e].lower_bound(i);
    int a_l, a_r;
    if (l != team[e].begin()) {
        l--;
        a_l = i - *l;
    } else {
        l = team[e].end();
        l--;
        a_l = i + n - *l;
    }
    auto r = team[e].upper_bound(i);
    if (r == team[e].end()) {
        a_r = n - i + *team[e].begin();
    } else a_r = *r - i;
    return pii(a_l, a_r);
}

int main() {
    scanf(" %d %d", &n, &f);
    scanf(" %d %d %d", &a, &b, &c);
    set_t();
    scanf(" %d", &m);
    while (m--) {
        int i, e;
        scanf(" %d %d", &i, &e);
        team[t[i]].erase(i);
        pii ans = query(i, e);
        team[e].insert(i);
        t[i] = e;
        printf("%d %d\n", ans.ff, ans.ss);
    }
}

