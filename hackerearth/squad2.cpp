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
const int MAX = 204;
const int modn = 1000000007;

int N, K;
int mdp[MAX][MAX];

int dp (int n, int k) {
    if (k < K || n < 0) return 0;
    if (n == 0) return 1;
    if (mdp[n][k] != -1) return mdp[n][k];
    return dp (n-k, k) + dp (n, k-1);
}

int main() {
    int t;
    scanf (" %d", &t);
    while (t--) {
        memset (mdp, -1, sizeof mdp);
        scanf (" %d %d", &N, &K);
        printf ("%d\n", dp (N, N));
    }
}

