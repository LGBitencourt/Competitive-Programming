#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 112345;

int from[MAXN], to[MAXN], n, sum, s[MAXN], c[MAXN];

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf(" %d %d", &x, &y);
        x--, y--;
        from[i] = x, to[i] = y;
    }
    for (int i = 0; i < n; i++)
        scanf(" %d", c + i);
    for (int i = 0; i < n - 1; i++)
        if (c[from[i]] != c[to[i]])
            s[from[i]]++, s[to[i]]++, sum++;
    for (int i = 0; i < n; i++)
        if (s[i] == sum) {
            printf("YES\n%d\n", i + 1);
            return 0;
        }
    puts("NO");
}

