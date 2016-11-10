#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
/////////////////0123456789
const int MAXN = 10004;

char a[MAXN], b[MAXN];
int ans[MAXN];

int main() {
    scanf(" %s", a);
    scanf(" %s", b);
    int n = strlen(a) - 1;
    for (int i = n; i >= 0; i--) {
        int x = a[i] - '0', y = b[i] - '0';
        ans[i] = (x ^ y);
    }
    for (int i = 0; i <= n; i++)
        printf("%d", ans[i]);
    puts("");
}

