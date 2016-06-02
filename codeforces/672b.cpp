#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
////////////////0123456789
const int MAX = 1000005;
const int modn = 1000000007;

int main() {
    int n, ans = 0;

    int c[30];
    char s;
    scanf (" %d", &n);
    memset (c, 0, sizeof c);
    for (int i = 0; i < n; i++) {
        scanf (" %c", &s);
        c[s - 'a']++;
    }
    if (n > 26) printf ("-1\n");
    else {
        for (int i = 0; i < 26; i++)
            if (c[i] > 1) ans += c[i] - 1;
        printf("%d\n", ans);
    }
}

