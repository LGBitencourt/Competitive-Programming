#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 112;

int n, m, moves = 0;
bool inv = false;
vector<int> r, c;
int g[MAXN][MAXN], a[MAXN][MAXN], tmp[MAXN][MAXN];

void print() {
    printf("%d\n", moves);
    for (int i : r) printf("%s %d\n", !inv ? "row" : "col", i);
    for (int i : c) printf("%s %d\n", !inv ? "col" : "row", i);
}

bool check() {
    bool ok = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] != g[i][j])
                ok = false;
    return ok;
}

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf(" %d", &g[i][j]);
    if (m < n) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                tmp[i][j] = g[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                g[j][i] = tmp[i][j];
        swap(n, m);
        inv = true;
    }
    for (int i = 0; i < n; i++) {
        int mi = inf;
        for (int j = 0; j < m; j++)
            mi = min(mi, g[i][j]);
        for (int j = 0; j < m; j++)
            a[i][j] += mi;
        if (mi) {
            moves += mi;
            for (int k = 0; k < mi; k++)
                r.push_back(i + 1);
        }
    }
    if (check()) print();
    else {
        for (int i = 0; i < m; i++) {
            int mi = inf;
            int mai;
            for (int j = 0; j < n; j++) {
                if (g[j][i] < mi)
                    mi = g[j][i], mai = a[j][i];
            }
            mi -= mai;
            for (int j = 0; j < n; j++)
                a[j][i] += mi;
            if (mi) {
                moves += mi;
                for (int k = 0; k < mi; k++)
                    c.push_back(i + 1);
            }
        }
        if (check()) print();
        else puts("-1");
    }

}

