#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = inf;
/////////////////0123456789
const int MAXN = 104;
const int modn = 1000000007;

bool mr[MAXN], mc[MAXN];
int grid[MAXN][MAXN];

int main() {
    int r, c, ans = 0;
    scanf(" %d %d", &r, &c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            char s;
            scanf(" %c", &s);
            if (s == 'S') mr[i] = mc[j] = true;
            else grid[i][j] = 1;
        }
    for (int i = 0; i < r; i++) {
        if (mr[i]) continue;
        for (int j = 0; j < c; j++) {
            ans += grid[i][j];
            grid[i][j] = 0;
        }
    }
    for (int j = 0; j < c; j++) {
        if (mc[j]) continue;
        for (int i = 0; i < r; i++) {
            ans += grid[i][j];
            grid[i][j] = 0;
        }
    }
    printf("%d\n", ans);
}

