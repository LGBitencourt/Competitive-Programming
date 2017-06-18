#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 11234;

int main() {
    int h, m, ans = 0;
    scanf(" %d:%d", &h, &m);
    while ((h / 10) != (m % 10) || (h % 10) != m / 10) {
        m++, ans++;
        if (m == 60) h++, m = 0;
        if (h == 24) h = 0;
    }
    printf("%d\n", ans);
}

