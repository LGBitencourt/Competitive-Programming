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

int n;
int ans[MAXN];

int main() {
    scanf(" %d", &n);
    for (int i = 0; i <= n*n/2; i++)
        ans[i + 1] = n*n - i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n/2; j++)
            printf("%d %d ", i*(n/2) + j + 1, ans[i*(n/2) + j + 1]);
        puts("");
    }
}

