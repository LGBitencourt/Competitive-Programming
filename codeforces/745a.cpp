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

char c[MAXN], tmp[MAXN];
set<string> s;

int main() {
    int n;
    scanf(" %s", c);
    n = strlen(c);
    for (int i = 0; i < n; i++) {
        s.insert(c);
        tmp[0] = c[n - 1];
        for (int j = 1; j < n; j++)
            tmp[j] = c[j - 1];
        for (int j = 0; j < n; j++)
            c[j] = tmp[j];
    }
    printf("%d\n", (int) s.size());
}

