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
const int MAXN = 500004;

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

    queue<int> q;
    q.push(1);
    cnt[1] = n;
    while (!q.empty()) {
        int v = q.front();
        q.pop();

    }

    for (int i = 0; i < m; i++)     
        e[i] = s[i + 1] + (cnt[i + 1] % 2LL);
    for (int i = 0; i < m; i++) {
        if (e[i] & 1) printf("R");
        else printf("L");
    }
    printf("\n");
}

