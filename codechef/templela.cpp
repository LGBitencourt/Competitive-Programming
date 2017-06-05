#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 112;

int tmp[MAXN];

int main() {
    int s, n;
    scanf(" %d", &s);
    while (s--) {
        scanf(" %d", &n);
        bool ok = true;
        for (int i = 0; i < n; i++)
            scanf(" %d", tmp + i);
        if (!(n & 1) || tmp[0] != 1) ok = false;
        for (int i = 0; i < n / 2; i++)
            if (tmp[i] != i + 1) ok = false;
        for (int i = n / 2; i < n; i++)
            if (tmp[i] != n - i) ok = false;
        printf("%s\n", ok ? "yes" : "no");
    }
}

