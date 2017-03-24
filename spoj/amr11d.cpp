#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 112;

int s[MAXN];

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        int n, sum = 0, ans = 0;
        scanf(" %d", &n);
        for (int i = 0; i < n; i++) {
            scanf(" %d", s + i);
            sum += s[i];
        }
        int cs = 0;
        sort(s, s + n);
        for (int i = 0; i < n; i++) {
            cs += s[i];
            if (cs < i*(i + 1)/2) {
                ans += (i*(i + 1)/2 - cs);
                cs = i*(i+1)/2;
            }
        }
        ans += cs - (n * (n - 1) / 2);
        printf("%d\n", ans);
    }
}

