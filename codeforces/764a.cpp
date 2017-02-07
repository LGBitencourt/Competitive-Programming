#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 11234;

int main() {
    int n, m, z, ans = 0;
    scanf(" %d %d %d", &n, &m, &z);
    for (int i = 1; i <= z; i++)
        if (i % n == 0 && i % m == 0) ans++;
    printf("%d\n", ans);
}

