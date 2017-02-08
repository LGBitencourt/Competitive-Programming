#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 112345;

int a[MAXN];

int main() {
    int n;
    bool ans = false;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %d", a + i);
    sort(a, a + n);
    for (int i = 2; i < n; i++) {
        int x = a[i - 2], y = a[i - 1], z = a[i];
        if (x + y > z && x + z > y && y + z > x) ans = true;
    }
    printf("%s\n", ans ? "YES" : "NO");
}

