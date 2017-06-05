#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 11234;

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        int n, m;
        scanf(" %d %d", &n, &m);
        for (int i = 0; i < m; i++)
            scanf(" %*d %*d");
        if ((n & 1)) puts("no");
        else puts("yes");
    }
}

