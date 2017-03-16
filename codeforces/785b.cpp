#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 212345;

pii chess[MAXN], prog[MAXN];

bool cmp(pii a, pii b) {
    if (a.ss != b.ss) return a.ss < b.ss;
    return a.ff < b.ff;
}

int main() {
    int n, m, ans = 0;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf(" %d %d", &x, &y);
        chess[i] = pii(x, y);
    }
    scanf(" %d", &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf(" %d %d", &x, &y);
        prog[i] = pii(x, y);
    }
    sort(chess, chess + n);
    sort(prog, prog + m, cmp);
    //printf("(%d %d) (%d %d)\n", chess[n-1].ff, chess[n-1].ss, prog[0].ff, prog[m-1].ss);
    ans = max(0, prog[0].ss < chess[n - 1].ff ? abs(chess[n-1].ff - prog[0].ss) : 0);
    sort(chess, chess + n, cmp);
    sort(prog, prog + m);
    //printf("(%d %d) (%d %d)\n", prog[m-1].ff, prog[m-1].ss, chess[0].ff, chess[0].ss);
    ans = max(ans, chess[0].ss < prog[m - 1].ff ? abs(prog[m - 1].ff - chess[0].ss) : 0);
    printf("%d\n", ans);
}

