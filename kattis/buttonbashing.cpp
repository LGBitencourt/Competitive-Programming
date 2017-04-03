#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 11234;

int n;
int b[MAXN], d[MAXN];

void bfs() {
    memset(d, inf, sizeof d);
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while (q.size()) {
        int c = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            int nw = max(0, min(b[i] + c, 3600));
            if (d[nw] > d[c] + 1) {
                q.push(nw);
                d[nw] = d[c] + 1;
            }
        }
    }
}

int main() {
    int tt;
    scanf(" %d", &tt);
    while (tt--) {
        int t;
        scanf(" %d %d", &n, &t);
        for (int i = 0; i < n; i++)
            scanf(" %d", b + i);
        bfs();
        if (d[t] < inf) printf("%d 0\n", d[t]);
        else {
            int s = t;
            while (t <= 3600 && d[t] >= inf) t++;
            printf("%d %d\n", d[t], t - s);
        }
    }
}

