#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1000004;

int e[MAXN], s[MAXN], in[MAXN];
int adj[MAXN][2];
ll cnt[MAXN];

int main() {
    int m;
    ll n;
    scanf(" %lld %d", &n, &m);
    for (int i = 0; i < m; i++) {
        char c;
        int l, r;
        scanf(" %c %d %d", &c, &l, &r);
        adj[i + 1][0] = l, adj[i + 1][1] = r;
        s[i + 1] = (c == 'R');
        in[l]++, in[r]++;
    }

    set<int> q;
    for (int i = 1; i <= m; i++)
        if (!in[i]) q.insert(i);
    cnt[1] = n;
    while (q.size()) {
        int v = *(q.begin());
        q.erase(q.begin());
        if (v == 0) continue;
        int l, r;
        l = adj[v][0], r = adj[v][1];
        cnt[l] += (cnt[v] / 2LL);
        cnt[r] += (cnt[v] / 2LL);
        if (cnt[v] & 1LL) cnt[adj[v][s[v]]]++;
        in[l]--, in[r]--;
        if (in[l] == 0) q.insert(l);
        if (in[r] == 0) q.insert(r);
    }

    for (int i = 0; i < m; i++)     
        e[i] = s[i + 1] + (cnt[i + 1] & 1LL);

    for (int i = 0; i < m; i++) {
        if (e[i] & 1) printf("R");
        else printf("L");
    }
    printf("\n");
}

