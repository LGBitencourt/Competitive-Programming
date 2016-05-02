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
const int MAX = 10005;
const int modn = 1000000007;

char s[MAX], p[MAX];
int n, m;
ll b = 31, bn = 1;
ll rolling_hash, hash_p;

int main() {
    scanf (" %s %s", s, p);
    hash_p = rolling_hash = 0;
    n = strlen(p), m = strlen(s);
    for (int i = 0; i < n; i++) {
        hash_p = hash_p * b + p[i];
        rolling_hash = rolling_hash * b + s[i];
        bn *= b;
    }
    if (hash_p == rolling_hash)
        printf ("[%d, %d]\n", 0, n-1);
    for (int i = 1; i < m - n + 1; i++) {
        rolling_hash = (rolling_hash * b + s[i + n - 1] - bn * s[i-1]);
        if (rolling_hash >= modn) rolling_hash -= modn;
        if (hash_p == rolling_hash)
            printf ("[%d, %d]\n", i, i + n - 1);
    }
}

