#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 11234;

int g[5][5], p[5];

int main() {
    bool a = false;
    for (int i = 0; i < 4; i++)
        scanf(" %d %d %d %d", &g[i][0], &g[i][1], &g[i][2], &p[i]);

    if (p[0] == 1) {
        for (int i = 0; i < 3; i++)
            if (g[0][i] == 1) a = true;
        if (g[2][1] == 1 || g[1][0] || g[3][2] == 1)  a = true;
    }
    if (p[1] == 1) {
        for (int i = 0; i < 3; i++)
            if (g[1][i] == 1) a = true;
        if (g[0][2] == 1 || g[2][0] == 1 || g[3][1]) a = true;
    }
    if (p[2] == 1) {
        for (int i = 0; i < 3; i++)
            if (g[2][i] == 1) a = true;
        if (g[0][1] == 1 || g[3][0] == 1 || g[1][2]) a = true;
    }
    if (p[3] == 1) {
        for (int i = 0; i < 3; i++)
            if (g[3][i] == 1) a = true;
        if (g[1][1] == 1 || g[0][0] == 1 || g[2][2]) a = true;
    }
    printf("%s\n", a ? "YES" : "NO");
}

